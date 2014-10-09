For Filter Policy,
it stored at ~resources/filterPolicy.txt,
it represented as,
PORT:USER:ACCESS:TRIGGER:OPTION
4013:aany:rwx:5:all

For Alert Policy,
it stored at ~resources/alertPolicy.txt,
it represented as,
PORT/RULE:USER:ACCESS:TRIGGER:OPTION
rule3:any:rwx:2:day

For Logging from Filter,
it stored at ~log.txt,
it represented as,
RULE,PORT,OPTION|USER,READ,WRITE,EXECUTE: USER, ...:
3,4000,day|A,1,2,5:B,2,3,4:...Z:0,5,0:

For Alert from Analyzer,
it stored at ~alert.txt,
it represented as, USER:ACTION:TRIGGER:PORT:DAY
user:X, action: write exceed 3 on port 4017 in day 7


For more information, please look at the Full Documentation submitted.