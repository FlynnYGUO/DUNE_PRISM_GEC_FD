# DUNE_PRISM
## I. Preparations 
> Instructions:  
> - https://github.com/weishi10141993/myntuples (DUNE_PRISM)   
> - https://indico.cern.ch/event/1058873/timetable/  (General Linux). 
1. [Create a SBU ivy account](https://docs.joyent.com/public-cloud/getting-started/ssh-keys/generating-an-ssh-key-manually)
2. Log into Ivy then Set up SBU Ivy work area, copied from Dr. Wei Shi's Github (see Instructions)  
- Log in:
```
ssh -AY fyguo@ivy.physics.sunysb.edu       # Log my ivy account: <username>@ivy.physics.sunysb.edu
passwd                                     # Reset my password  
exit                                       # Quit ivy
```
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
- To run on FD MC files, this produces a TTree in myntuple.root in your work area:
```
cd /home/<your_username>/FDEff/srcs/myntuples/myntuples/MyEnergyAnalysis
# For example: cd /home/fyguo/FDEff/srcs/myntuples/myntuples/MyEnergyAnalysis
lar -c MyEnergyAnalysis_ivy.fcl -n 10 -s /storage/shared/cvilela/DUNE_FD_MC/nu_dune10kt_1x2x6_13422341_0_20181123T225730_gen_g4_detsim_reco.root
```
3. The next time you login the ivy machine (username@ivy.physics.sunysb.edu), do the following to set up:
```
source /home/wshi/ups/setup
setup mrb
setup dunetpc v08_62_01 -q e19:py2:prof
source /home/<your_username>/FDEff/localProducts_larsoft_v08_62_01_e19_prof_py2/setup
#For example: source /home/fyguo/FDEff/localProducts_larsoft_v08_62_01_e19_prof_py2/setup
mrbsetenv

# Go to your work directory and run your study!
cd /home/<your_username>/FDEff/srcs/myntuples/myntuples/MyEnergyAnalysis
# For example: cd /home/fyguo/FDEff/srcs/myntuples/myntuples/MyEnergyAnalysis
```

4. Always transfer file outside the ssh and use ROOT locally:
> Go back to your local working dir.
```
scp <filename> <local directory>                                                         # Transfer file to local laptop (recommend use ROOT locally)
# For example: scp fyguo@ivy.physics.sunysb.edu:/home/fyguo/FDEff/srcs/myntuples/myntuples/MyEnergyAnalysis/myntuple.root ~/Documents/Codes/DUNE/DUNE_PRISM/GeometricEfficiencyCorrections
```
