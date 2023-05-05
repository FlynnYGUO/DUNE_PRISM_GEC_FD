## Linux commands:
``` cd ``` Go to sub-directory  
``` cd .. ``` Go back to directory  
``` ls ``` List files in this directory  
``` ls -a ``` List all files including hiding files in this directory  
``` ls -lh ``` List all files including size and time of files   
``` ls -lrth ``` List all files including size and time of files   
``` rm ``` Delete a file  
``` rm -rf foldername ``` Delete a non-empty directory in Terminal  
``` pwd ``` List the current dir.  
``` scp <filename> <local directory> ``` Transfer file to local laptop
``` ls *.pdf ``` List all pdf(png, jpg, etc.) files  
``` mv <filename> <directory> ``` Move file to another directory  
``` touch config ``` Create a config file  
``` open -t <filename> ``` Use default text editor to open file    
``` git pull ``` Update a local repository from the corresponding remote repository  
``` vi <filename> ``` Open and edit the file. For more info. on vi editor, plz see this [tutorial](https://www.cs.colostate.edu/helpdocs/vi.html)  
``` git clone https://github.com/FlynnYGUO/DUNE_ND_GeoEff.git -b FD_Wei .``` Git clone a branch to local    
``` rsync -e ssh -avSz ./* fyguo@ivy.physics.sunysb.edu:/home/fyguo/DUNE_ND_GeoEff``` Update all files in current folder to IVY machine  
