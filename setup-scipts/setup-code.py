import logging
import os
import yaml
import configparser

OPEN5GS = "/home/yj/Desktop/ORBIT/src/open5gs/"
SRSCONFIG = "/home/yj/Desktop/ORBIT/src/srsRAN_config/"

logger = logging.getLogger()

logger.setLevel(logging.INFO)
formatter = logging.Formatter('%(asctime)s %(levelname)s::%(message)s')

stream_handler = logging.StreamHandler()
stream_handler.setFormatter(formatter)
logger.addHandler(stream_handler)

file_handler = logging.FileHandler('my.log')
file_handler.setFormatter(formatter)
logger.addHandler(file_handler)

################# Set Open5GS Env #################

logger.info('Set Open5GS Env')


################# Modify sample.yaml #################

sample_yaml_path = os.path.join(OPEN5GS + 'build/configs', 'sample.yaml')


logger.info('Modify sample.yaml')

with open(sample_yaml_path, 'r') as read_file:
    contents = yaml.safe_load(read_file)

contents['amf']['ngap'][0]['addr'] = '127.0.0.2'

contents['amf']['guami'][0]['plmn_id']['mcc'] = 901
contents['amf']['guami'][0]['plmn_id']['mnc'] = 70

contents['amf']['tai'][0]['plmn_id']['mcc'] = 901
contents['amf']['tai'][0]['plmn_id']['mnc'] = 70
contents['amf']['tai'][0]['tac'] = 7

contents['amf']['plmn_support'][0]['plmn_id']['mcc'] = 901
contents['amf']['plmn_support'][0]['plmn_id']['mnc'] = 70

contents['upf']['gtpu'][0]['addr'] = '127.0.0.2'

with open(sample_yaml_path, 'w') as read_file:
    yaml.safe_dump(contents, read_file, default_flow_style=False, sort_keys=False)


logger.info('Successfully changed sample.yaml')

################# ################# #################

################# Add UserSIM Info ##################

logger.info("Add UserSIM Info")
dbctl_path = os.path.join(OPEN5GS + 'build/misc/db')


logger.info('Prev path: ' + os.getcwd())
os.chdir(dbctl_path)
logger.info('Curr path: ' + os.getcwd())

# remove prev usersim info
os.system('./open5gs-dbctl remove 901700123456789')

# add usersim info
os.system('./open5gs-dbctl add 901700123456789 00112233445566778899aabbccddeeff 000102030405060708090a0b0c0d0e0f')
os.system('./open5gs-dbctl showfiltered')

################# ################# #################

################## Make Run File ####################

logger.info('Prev path: ' + os.getcwd())
os.chdir(OPEN5GS)
logger.info('Curr path: ' + os.getcwd())



run_file_name = 'net.sh'

with open(run_file_name, 'w') as f:
    f.write("#!/bin/bash\nsudo ip tuntap add name ogstun mode tun\nsudo ip addr add 10.45.0.1/16 dev ogstun\
    \nsudo ip addr add 2001:db8:cafe::1/48 dev ogstun\nsudo ip link set ogstun up\n./build/tests/app/5gc")

logger.info('Successfully created net.sh')

################# ################# #################

################## Run Open5GS ####################

logger.info('Change permission on net.sh')
os.system('chmod 777 net.sh')

logger.info('Run OpenGCS')

os.system('sudo systemctl start mongod')
os.system('qwer1234 ENTER')


logger.info('Create tmux session')
run_cmd = "sh -v ./net.sh"
tmux_create_session = 'tmux new-session -d -s ' + 'Open5GC'
tmux_run_cmd = 'tmux send -t ' + 'Open5GC' + ' "' + run_cmd + '" ENTER'
os.system(tmux_create_session)
os.system(tmux_run_cmd)
os.system('tmux send -t ' + 'Open5GC' + ' "' + 'qwer1234' + '" ENTER')


################# ################# #################

################# Set srsENB Env #################

################# Modify enb.conf #################

logger.info('Modify enb.conf')
cp = configparser.ConfigParser()
enb_conf_path = SRSCONFIG + "enb.conf"

cp.read(enb_conf_path)

cp.set('enb_files', 'sib_config', SRSCONFIG+'sib.conf')
cp.set('enb_files', 'rr_config', SRSCONFIG+'rr.conf')
cp.set('enb_files', 'rb_config', SRSCONFIG+'rb.conf')

cp.set('enb', 'mcc', '901')
cp.set('enb', 'mnc', '70')
cp.set('enb', 'mme_addr', '127.0.0.2')

cp.set('rf', 'tx_gain', '80')
cp.set('rf', 'rx_gain', '20')
cp.set('rf', 'device_name', 'auto')
cp.set('rf', 'device_args', 'clock=internal')

cp.set('scheduler', 'nr_pdsch_mcs', '0')
cp.set('scheduler', 'nr_pusch_mcs', '0')

os.remove(enb_conf_path)

with open(enb_conf_path, 'w') as read_file:
    cp.write(read_file)

logger.info('Successfully created enb.conf')

################# ################# #################

################## Run srsRAN ####################

logger.info('Create srsenb tmux session')
run_cmd = "sudo srsenb " + enb_conf_path
tmux_create_session = 'tmux new-session -d -s ' + 'srsENB'
tmux_run_cmd = 'tmux send -t ' + 'srsENB' + ' "' + run_cmd + '" ENTER'
os.system(tmux_create_session)
os.system(tmux_run_cmd)
os.system('tmux send -t ' + 'srsENB' + ' "' + 'qwer1234' + '" ENTER')




