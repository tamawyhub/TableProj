from datetime import datetime as dt
import sys

f=open("session log.txt","a")
sgn=''
if (sys.argv[1]=="open"):
	sgn='+ '
elif (sys.argv[1]=="close"):
	sgn='- '
else:
	print("ERROR")
	exit()

f.write(sgn+dt.today().ctime()+'\n')