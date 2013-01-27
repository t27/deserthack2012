#Python Script to convert wav file to chunks of 15sec flac files
#Author Tarang Shah
import sys
import os
import commands
if len(sys.argv[:])<2:
  print "Usage : python script.py /path/to/file.wav"
filenam=sys.argv[1]
wavfilename=(filenam.split('/'))[-1]

filelen=float(commands.getoutput("sox --i -D "+filenam))

i=0
a=1
#if os.path.exists(filenam[:-4])==False:
#  os.mkdir(filenam[:-4])
if os.path.exists("./SavedRecordings/")==False:
  os.mkdir("./SavedRecordings")
if os.path.exists("./SavedRecordings/"+wavfilename[:-4]+"/")==False:
  os.mkdir("./SavedRecordings/"+wavfilename[:-4])
else:
  os.system("rm ./SavedRecordings/"+wavfilename[:-4]+"/*.*");
##while i<filelen:
 ## if (filelen-i)>15:
	#os.system("sox "+filenam+" "+filenam[:-4]+"/"+str(a)+".wav trim "+str(i)+" 15")
	##os.system("sox "+filenam+" ./SavedRecordings/"+wavfilename[:-4]+"/"+str(a)+".wav trim "+str(i)+" 15")
os.system("sox "+filenam+" ./SavedRecordings/"+wavfilename[:-4]+"/out.wav silence 1 0.1 10% 1 0.5 10% : newfile : restart");

  ##else:
	#os.system("sox "+filenam+" "+filenam[:-4]+"/"+str(a)+".wav trim "+str(i))
	##os.system("sox "+filenam+" ./SavedRecordings/"+wavfilename[:-4]+"/"+str(a)+".wav trim "+str(i))
#  i+=15
#  a+=1
#a-=1
nooffiles=int(commands.getoutput("ls -l ./SavedRecordings/"+wavfilename[:-4]+"/ | wc -l"))-1
a=1
while a<=nooffiles:
  #os.system("sox "+filenam[:-4]+"/"+str(a)+".wav "+filenam[:-4]+"/"+str(a)+".flac rate 16k")
  #os.system("rm "+filenam[:-4]+"/"+str(a)+".wav");
  if a<10:
	astr="00"+str(a)
  elif a<100:
	astr="0"+str(a)
  else:
	astr=str(a)
  os.system("sox "+"./SavedRecordings/"+wavfilename[:-4]+"/out"+astr+".wav "+"./SavedRecordings/"+wavfilename[:-4]+"/"+str(a)+".flac rate 16k")
  os.system("rm "+"./SavedRecordings/"+wavfilename[:-4]+"/out"+astr+".wav")
  a+=1;
  

