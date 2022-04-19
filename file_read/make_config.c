#include<stdlib.h>
#include<stdio.h>
#include<string.h>
/*
packetbeat.interfaces.device:any
*/
void make_config(){
    char device[0x100]="packetbeat.interfaces.device:any\n";
    char flows[0x100]="packetbeat.flows:\n    timeout: 10s\n    period: 10s\n";
    char processors[0x100] = \
    "prossors:\n\
     - drop_event:\n\
        when:\n\
          not:\n\
           network:\n";
    char destion_ip[0x100]="            destination.ip: [%s]\n";
    char src_ip[0x100] =   "            source.ip: [%s]\n";
    char ilm_setup[0x100] = "setup.ilm.enabled: auto\n";
    char ilm_setup_rollover[0x100] = "setup.ilm.rollover_alias: blockchaintest\n";
    char ilm_setup_pattern[0x100] = "setup.ilm.pattern: \"{now/d}-0000001\"\n";
    char output[0x100] = "output.elasticsearch:\n    hosts: '10.10.7.55:9200'\n";
    char* write_lines[0x100]={device,flows,processors,destion_ip,src_ip,ilm_setup,\
                ilm_setup_rollover,\
                ilm_setup_pattern,\
                output
                };
    int n = 9;
    for (int i=0;i<n;i++){
        if(!strcmp(write_lines[i],destion_ip)){
            printf(destion_ip,"192.168.14.0/24");
        }else{
            printf("%s",write_lines[i],i);

        }
    }
}
int main(){
    make_config();
    return 1;
}