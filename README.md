# DUNE_PRISM
> Geometric Efficiency Correction  
> Remote sync from local to ssh (Ivy): go to local directory then use    
> ```rsync -e ssh -avSz ./* fyguo@ivy.physics.sunysb.edu:/home/fyguo/NDEff/DUNE_ND_GeoEff/```.     
> ```rsync -e ssh -avSz ./* fyguo@ivy.physics.sunysb.edu:/home/fyguo/FDEff/srcs/myntuples```.    
> Remote sync from local to ssh (FNAL): go to local directory (eg. DUNE_ND_GeoEff) then use   
> ```rsync -e ssh -avSz ./* flynnguo@dunegpvm15.fnal.gov:/dune/app/users/flynnguo/NDEff/DUNE_ND_GeoEff/```.  
> ```rsync -e ssh -avSz ./* flynnguo@dunegpvm15.fnal.gov:/dune/app/users/flynnguo/FDEff/srcs/myntuples```.  
## FNAL Machine
> - [DUNE Computing Tutorial](https://wiki.dunescience.org/wiki/DUNE_Computing_Tutorial_January_2021)
> - Some [instructions](https://uscms.org/uscms_at_work/physics/computing/getstarted/uaf.shtml#MacBigSur) on connecting the FNAL machine 
> Dr. Wei Shi's instruction: https://github.com/weishi10141993/myntuples#dune-fnal-machines-dunegpvm-environment-setup
### I. Preparations
#### 1. [Apply a Fermilab account](https://get-connected.fnal.gov/accessandbadging/access/)
- Log in:
```
kfnal                                      # Short for kinit -f <username>@FNAL.GOV. In my laptop, alias kfnal="/usr/bin/kinit flynnguo@FNAL.GOV" in ~/.zshrc
ssh -X flynnguo@dunegpvm15.fnal.gov
exit                                       # Quit FNAL
```
#### 2. DUNE FNAL machines (dunegpvm*) environment setup
- Set up (first time only) 
```
cd /dune/app/users/flynnguo                                             # Replace with your username for all commands below
mkdir FDEff (first time only)
cd FDEff

source /cvmfs/dune.opensciencegrid.org/products/dune/setup_dune.sh
setup dunetpc v09_22_02 -q e19:debug
[optional if run interactively] setup_fnal_security                     # A FNAL grid proxy to submit jobs and access data in dCache via xrootd or ifdh.

mrb newDev
# The prompt ask you to run this:
source /dune/app/users/<your_username>/inspect/localProducts_larsoft_${LARSOFT_VERSION}_debug_${COMPILER}/setup
# For example, mine is: source /dune/app/users/flynnguo/FDEff/localProducts_larsoft_v09_22_02_debug_e19/setup

cd srcs
git clone https://github.com/FlynnYGUO/myntuples.git                    # First time only, checkout the analysis code from GitHub

mrb uc                                                                  # Tell mrb to update CMakeLists.txt with the latest version numbers of the products.
cd ${MRB_BUILDDIR}                                                      # Go to your build directory
mrb z
mrbsetenv                                                               # Create the bookkeeping files needed to compile programs.
mrb b                                                                   # Compile the code in ${MRB_SOURCE} and put the results in ${MRB_INSTALL}
```

### II. Generate the FD events
- The next time you login a DUNE FNAL machine (dunegpvm*), do the following to set up:
```
source /cvmfs/dune.opensciencegrid.org/products/dune/setup_dune.sh
setup dunetpc v09_22_02 -q e19:debug
source /dune/app/users/flynnguo/FDEff/localProducts_larsoft_v09_22_02_debug_e19/setup
mrbsetenv
mrb b
```
- Produce Ntuple from DUNE FD MC files:
```
cd /dune/app/users/flynnguo/FDEff/srcs/myntuples/myntuples/MyEnergyAnalysis
lar -c MyEnergyAnalysis.fcl -n -1
# Or run with nohup (recommended)
nohup lar -c MyEnergyAnalysis.fcl -n -1 >& out_myntuple_nohup.log &             
# check status: jobs -l
# Run this for all events (-n -1 means run all events, -n 10 just ran 10 events)
# 10k evts take about 32 minutes
```
- If added new package in srcs directory, do ```mrb uc``` and then recompile as above.
- If changed ```MyEnergyAnalysis_module.cc```, recompile the code (do the setup above first):
```
cd ${MRB_BUILDDIR}                        # Go to your build directory
mrb z                                     # Remove old build directory
mrbsetenv                                 # Create the bookkeeping files needed to compile programs.
mrb b                                     # Compile the code in ${MRB_SOURCE} and put the results in ${MRB_INSTALL}                              
```
- Copy ntuple files back into my local laptop
```
scp flynnguo@dunegpvm15.fnal.gov:/dune/app/users/flynnguo/FDEff/srcs/myntuples/myntuples/MyEnergyAnalysis/myntuple.root .
```
### III. Running translation and rotations on FD n-tuples
> Instructions:  
> - https://github.com/weishi10141993/DUNE_ND_GeoEff/tree/FD_Wei#instruction-for-running-translation-and-rotations-on-fd-n-tuples 
> - Prerequisite: [Produced root file from DUNE FD MC files](https://github.com/FlynnYGUO/DUNE_PRISM/blob/main/README.md#3-recompile-and-rerun). The produced FD n-tuples will be used as input files for the following program to run.
#### 1. Set up work area (First time only)
```
cd /dune/app/users/flynnguo 
mkdir NDEff (first time only)
cd NDEff
git clone --recursive -b FD_Wei https://github.com/FlynnYGUO/DUNE_ND_GeoEff.git      # Get geoEff library
cd DUNE_ND_GeoEff
source setup.sh                                                                                    # Necessary setups for build
cmake -DPYTHON_EXECUTABLE:FILEPATH=`which python` .
make -j geoEff                                                                                     # Build geoEff (can also use: make -j pyGeoEff)
```
#### 2. (Re)compile and (re)run
- The next time you login the ivy machine, do the following to set up
```
cd /dune/app/users/flynnguo/NDEff/DUNE_ND_GeoEff/
#
# In case you log out, need to source setup.sh to setup ROOT
#
source setup.sh                                                                           
```
- Produce a root file containing throws and the hadron throw result
```
cd /dune/app/users/flynnguo/NDEff/DUNE_ND_GeoEff/app
make runGeoEffFDEvtSim                                                                             # Compile program
cd ../bin
./runGeoEffFDEvtSim  
```
#### 3. (Recommend) Use screen option even w/o connection to Ivy to (Re)compile and (re)run 
```
cd /dune/app/users/flynnguo/NDEff/DUNE_ND_GeoEff/
screen
source setup.sh
cd app/
make runGeoEffFDEvtSim                                                                             # Compile program
cd ../bin
nohup ./runGeoEffFDEvtSim >& out_throws_nohup.log &                                                
# Check status: jobs -l
# To detach from the screen session, press Ctrl+a (release) and then d to detach the process/screen.
# To resume detached process, use: screen -r
# 10k evts: 6.20pm start, end second day 4:52am, 10hrs32mins
# Copy the output root file into local laptop: scp flynnguo@dunegpvm15.fnal.gov:/dune/app/users/flynnguo/NDEff/DUNE_ND_GeoEff/bin/Output_FDGeoEff.root .
```
- Resume the screen session
```
screen -r
```





## SBU NN Ivy Machine
### I. Preparations and generate the FD events
> Instructions:  
> Most copied from Dr. Wei Shi's Github:
> - https://github.com/weishi10141993/myntuples 
> - https://github.com/weishi10141993/DUNE_ND_GeoEff/tree/FD_Wei#instruction-for-running-translation-and-rotations-on-fd-n-tuples
 
#### 1. [Create a SBU ivy account](https://docs.joyent.com/public-cloud/getting-started/ssh-keys/generating-an-ssh-key-manually)
- Log in:
```
ssh -AY fyguo@ivy.physics.sunysb.edu       # Log my ivy account: <username>@ivy.physics.sunysb.edu
passwd                                     # Reset my password  
exit                                       # Quit ivy
```
#### 2. Set up work area (First time only) 
- Install the DUNE software:
```
# I've done this part, so you can skip it
#
mkdir ~/ups
mkdir ~/upstars
cd upstars
wget https://scisoft.fnal.gov/scisoft/bundles/tools/pullProducts
chmod +x ./pullProducts
./pullProducts ~/ups slf6 dune-v08_62_01 e19-py2 prof                                    # Scientific Linux 6
#
# I've done the above, start from settings below
```
- Set up work area on Ivy: (first time only)
```
mkdir ~/FDEff                                                                            # First time only
cd ~/FDEff
source /home/wshi/ups/setup      
setup git
setup gitflow
setup mrb
setup dunetpc v08_62_01 -q e19:py2:prof

export MRB_PROJECT=larsoft                                                               # Need to set ${MRB_PROJECT} to the master product
mrb newDev
source /home/fyguo/FDEff/localProducts_larsoft_v08_62_01_e19_prof_py2/setup

cd srcs                            
git clone https://github.com/FlynnYGUO/myntuples.git                                     # First time only, checkout the analysis code from GitHub
cp /home/wshi/dune/product_deps  /home/fyguo/FDEff/srcs/myntuples/ups/product_deps       # Change version of larsoft, cetbuildtools, and qualifier list for dunetpc v08_62_01  

mrb uc                                                                                   # Tell mrb to update CMakeLists.txt with the latest version numbers of the products.
cd ${MRB_BUILDDIR}                                                                       # Go to your build directory
mrb z
mrbsetenv                                                                                # Create the bookkeeping files needed to compile programs.
# The working build directory is /home/fyguo/FDEff/build_slf6.x86_64
# The source code directory is /home/fyguo/FDEff/srcs
mrb install   
```

#### 3. (Re)compile and (re)run
- Log in:
```
ssh -AY fyguo@ivy.physics.sunysb.edu       # Log my ivy account: <username>@ivy.physics.sunysb.edu
```

- The next time you login the ivy machine (username@ivy.physics.sunysb.edu), do the following to set up
```
source /home/wshi/ups/setup
setup mrb
setup dunetpc v08_62_01 -q e19:py2:prof
source /home/fyguo/FDEff/localProducts_larsoft_v08_62_01_e19_prof_py2/setup
mrbsetenv
```

- Produce Ntuple from DUNE FD MC files
```
cd /home/fyguo/FDEff/srcs/myntuples/myntuples/MyEnergyAnalysis
lar -c MyEnergyAnalysis_ivy.fcl -n 10 -s /storage/shared/cvilela/DUNE_FD_MC/nu_dune10kt_1x2x6_13422341_0_20181123T225730_gen_g4_detsim_reco.root
#To run on FD MC files, this use 10 events to produce a TTree in myntuple.root in your work area
```
- Re-produce myntuple with more events to have more stats, 
> You can use these files on [```MyEnergyAnalysis_ivy.fcl```](https://github.com/FlynnYGUO/myntuples/blob/main/myntuples/MyEnergyAnalysis/MyEnergyAnalysis_ivy.fcl#L47): /storage/shared/cvilela/DUNE_FD_MC/nu_dune10kt_1x2x6_13422341_0_20181123T225730_gen_g4_detsim_reco.root
/storage/shared/cvilela/DUNE_FD_MC/nu_dune10kt_1x2x6_13422362_0_20181123T225714_gen_g4_detsim_reco.root
can add as many as you want (each file should have 100 events, so you probably can use all 10 nu_dune10kt*.root files there)  
```
lar -c MyEnergyAnalysis_ivy.fcl -n -1
# Run this for all events (-n -1 means run all events, -n 10 just ran 10 events)
```
> - If changed ```MyEnergyAnalysis_module.cc```, recompile the code (do the setup above first):
```
cd /home/fyguo/FDEff/build_slf6.x86_64    # Go to your build directory
mrb z                                     # Remove old build directory
mrbsetenv                                 # Create the bookkeeping files needed to compile programs.
mrb install                               # Compile the code in ${MRB_SOURCE} and put the results in ${MRB_INSTALL}
```
> - If added new package in ```srcs``` directory, do ```mrb uc``` and then recompile as above.
> - To commit changed code changes to remote repository:
``` 
git commit
git push
```
> - To commit changed code changes from remote repository:
``` 
git pull
```
- Always transfer file outside the ssh and use ROOT locally
> Go back to your local working dir.
```
scp <filename> <local directory>                                                         # Transfer file to local laptop (recommend use ROOT locally)
# For example: scp fyguo@ivy.physics.sunysb.edu:/home/fyguo/FDEff/srcs/myntuples/myntuples/MyEnergyAnalysis/myntuple.root .
# . represent the current dir in your local laptop
```

### II. Running translation and rotations on FD n-tuples
> Instructions:  
> - https://github.com/weishi10141993/DUNE_ND_GeoEff/tree/FD_Wei#instruction-for-running-translation-and-rotations-on-fd-n-tuples  
> - Prerequisite: [Produced root file from DUNE FD MC files](https://github.com/FlynnYGUO/DUNE_PRISM/blob/main/README.md#3-recompile-and-rerun). The produced FD n-tuples will be used as input files for the following program to run.
#### 1. Set up work area (First time only)
```
cd ~
mkdir NDEff (first time only)
cd NDEff
git clone --recursive -b FD_Wei https://github.com/FlynnYGUO/DUNE_ND_GeoEff.git      # Get geoEff library
cd DUNE_ND_GeoEff
source setup.sh                                                                                    # Necessary setups for build
cmake -DPYTHON_EXECUTABLE:FILEPATH=`which python` .
make -j geoEff                                                                                     # Build geoEff (can also use: make -j pyGeoEff)
```
#### 2. (Re)compile and (re)run
- The next time you login the ivy machine, do the following to set up
```
cd NDEff/DUNE_ND_GeoEff/
#
# In case you log out, need to source setup.sh to setup ROOT
#
source setup.sh                                                                           
```
- Produce a root file containing throws and the hadron throw result
```
cd NDEff/DUNE_ND_GeoEff/app
make runGeoEffFDEvtSim_ivy                                                                             # Compile program
cd ../bin
./runGeoEffFDEvtSim_ivy   
```
#### 3. (Recommend) Use screen option even w/o connection to Ivy to (Re)compile and (re)run 
- Before compile, go to the local directory then synchronize from local to ssh  
``` rsync -e ssh -avSz ./* fyguo@ivy.physics.sunysb.edu:/home/fyguo/NDEff/DUNE_ND_GeoEff/ ```
- Connect to ssh and recompile
```
cd NDEff/DUNE_ND_GeoEff/
screen
source setup.sh
cd app/
make runGeoEffFDEvtSim_ivy                                                                              # Compile program
cd ../bin
nohup ./runGeoEffFDEvtSim_ivy  >& out_throws_nohup.log &                                                
# Check status: jobs -l
# To detach from the screen session, press Ctrl+a (release) and then d to detach the process/screen.
# To resume detached process, use: screen -r
# 10k evts: 6.20pm start, end second day 4:52am, 10hrs32mins
# Copy the output root file into local laptop: 
# scp fyguo@ivy.physics.sunysb.edu:/home/fyguo/NDEff/DUNE_ND_GeoEff/bin/Output_FDGeoEff_ivy.root .
# scp fyguo@ivy.physics.sunysb.edu:/home/fyguo/NDEff/DUNE_ND_GeoEff/bin/Output_FDGeoEff_DataCheck_ivy.txt .
```
- Resume the screen session
```
screen -r
```

### III. Calculating FD event efficiency 
> Instructions:  
> - Prerequisite: [Produced root file from running translation and rotations on FD n-tuples](https://github.com/weishi10141993/DUNE_ND_GeoEff/tree/FD_Wei#instruction-for-calculate-fd-event-efficiency). The produced FD root file containing throws and the hadron throw result will be used as input files for the following program to run.
#### 1. Calculate FD event hadron containment efficiency 
```
cd NDEff/DUNE_ND_GeoEff
source setup.sh
cd app
root -l -b -q FDEffCalc_ivy.C
# 5k evts: 10mins
# scp fyguo@ivy.physics.sunysb.edu:/home/fyguo/NDEff/DUNE_ND_GeoEff/app/Output_GeoEff_ivy.txt .
# scp fyguo@ivy.physics.sunysb.edu:/home/fyguo/NDEff/DUNE_ND_GeoEff/app/Output_GeoEff_ivy.root .
```
#### 2. Export all graphics in FDEffCalc.root file
Go to the working directory, [tutorials](https://root-forum.cern.ch/t/saving-all-graphs-as-png-files/29330)
```
rootprint FDEffCalc_ivy.root
```
