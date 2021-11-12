# DUNE_PRISM
## I. Preparations 
> Instructions:  
> - https://github.com/weishi10141993/myntuples (DUNE_PRISM)   
> - https://indico.cern.ch/event/1058873/timetable/  (General Linux). 
### 1. [Create a SBU ivy account](https://docs.joyent.com/public-cloud/getting-started/ssh-keys/generating-an-ssh-key-manually)
- Log in:
```
ssh -AY fyguo@ivy.physics.sunysb.edu       # Log my ivy account: <username>@ivy.physics.sunysb.edu
passwd                                     # Reset my password  
exit                                       # Quit ivy
```
### 2. Set up work area (First time only)
> Copied from Dr. Wei Shi's Github (see Instructions)  
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
source /home/<username>/FDEff/localProducts_larsoft_v08_62_01_e19_prof_py2/setup
# For example: source /home/fyguo/FDEff/localProducts_larsoft_v08_62_01_e19_prof_py2/setup

cd srcs                            
git clone https://github.com/weishi10141993/myntuples.git                                # First time only, checkout the analysis code from GitHub
cp /home/wshi/dune/product_deps  /home/<username>/FDEff/srcs/myntuples/ups/product_deps  # Change version of larsoft, cetbuildtools, and qualifier list for dunetpc v08_62_01  
# For example: cp /home/wshi/dune/product_deps  /home/fyguo/FDEff/srcs/myntuples/ups/product_deps

mrb uc                                                                                   # Tell mrb to update CMakeLists.txt with the latest version numbers of the products.
cd ${MRB_BUILDDIR}                                                                       # Go to your build directory
mrb z
mrbsetenv                                                                                # Create the bookkeeping files needed to compile programs.
# The working build directory is /home/fyguo/FDEff/build_slf6.x86_64
# The source code directory is /home/fyguo/FDEff/srcs
mrb install   
```

### 3. (Re)compile and (re)run
- Log in:
```
ssh -AY fyguo@ivy.physics.sunysb.edu       # Log my ivy account: <username>@ivy.physics.sunysb.edu
```

- The next time you login the ivy machine (username@ivy.physics.sunysb.edu), do the following to set up
```
source /home/wshi/ups/setup
setup mrb
setup dunetpc v08_62_01 -q e19:py2:prof
source /home/<your_username>/FDEff/localProducts_larsoft_v08_62_01_e19_prof_py2/setup
#For example: source /home/fyguo/FDEff/localProducts_larsoft_v08_62_01_e19_prof_py2/setup
mrbsetenv
```

- Produce Ntuple from DUNE FD MC files
```
cd /home/<your_username>/FDEff/srcs/myntuples/myntuples/MyEnergyAnalysis
# For example: cd /home/fyguo/FDEff/srcs/myntuples/myntuples/MyEnergyAnalysis
lar -c MyEnergyAnalysis_ivy.fcl -n 10 -s /storage/shared/cvilela/DUNE_FD_MC/nu_dune10kt_1x2x6_13422341_0_20181123T225730_gen_g4_detsim_reco.root
#To run on FD MC files, this produces a TTree in myntuple.root in your work area
```

- Always transfer file outside the ssh and use ROOT locally
> Go back to your local working dir.
```
scp <filename> <local directory>                                                         # Transfer file to local laptop (recommend use ROOT locally)
# For example: scp fyguo@ivy.physics.sunysb.edu:/home/fyguo/FDEff/srcs/myntuples/myntuples/MyEnergyAnalysis/myntuple.root .
# . represent the current dir in your local laptop
```

## II. Running translation and rotations on FD n-tuples
> Instructions:  
> - https://github.com/weishi10141993/DUNE_ND_GeoEff/tree/FD_Wei#instruction-for-running-translation-and-rotations-on-fd-n-tuples  
> - Prerequisite: [Produced root file from DUNE FD MC files](https://github.com/FlynnYGUO/DUNE_PRISM/blob/main/README.md#3-recompile-and-rerun). The produced FD n-tuples will be used as input files for the following program to run.
### 1. Set up work area (First time only)
```
cd ~
mkdir NDEff (first time only)
cd NDEff
git clone --recurse-submodules -b FD_Wei https://github.com/weishi10141993/DUNE_ND_GeoEff.git      # Get geoEff library
# Note for git version (git --version) before 2.13, use: git clone --recursive -b FD_Wei https://github.com/weishi10141993/DUNE_ND_GeoEff.git
cd DUNE_ND_GeoEff
source setup.sh                                                                                    # Necessary setups for build
cmake -DPYTHON_EXECUTABLE:FILEPATH=`which python` .
make -j geoEff                                                                                     # Build geoEff (can also use: make -j pyGeoEff)
```
### 2. (Re)compile and (re)run
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
vi runGeoEffFDEvtSim                                                                               
# Change some commands like the location of the input file to my directory
make runGeoEffFDEvtSim                                                                             # Compile program
cd ../bin
./runGeoEffFDEvtSim  
```

## III. Calculating FD event efficiency 
> Instructions:  
> - Prerequisite: [Produced root file from running translation and rotations on FD n-tuples](https://github.com/weishi10141993/DUNE_ND_GeoEff/tree/FD_Wei#instruction-for-calculate-fd-event-efficiency). The produced FD root file containing throws and the hadron throw result will be used as input files for the following program to run.
1. Calculate FD event hadron containment efficiency 
```
cd NDEff/DUNE_ND_GeoEff
source setup.sh
cd app
vi FDEffCalc.C
# Change some commands like the location of the input file to my directory
root -l -b -q FDEffCalc.C
# 5k evts: 10mins
```
