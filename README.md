# DUNE_PRISM
## I. Preparations 
> Instructions:  
> - https://github.com/weishi10141993/myntuples (DUNE_PRISM)   
> - https://indico.cern.ch/event/1058873/timetable/  (General Linux). 
1. [Create a SBU ivy account](https://docs.joyent.com/public-cloud/getting-started/ssh-keys/generating-an-ssh-key-manually)
2. Set up SBU Ivy work area, copied from Dr. Wei Shi's Github (see Instructions)  
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
cd Documents/Codes/DUNE/DUNE_PRISM
mkdir FDEff                                                                            # First time only
cd FDEff
source ~/ups/setup 

STOP HERE!


setup git
setup gitflow
setup mrb
setup dunetpc v08_62_01 -q e19:py2:prof

export MRB_PROJECT=larsoft                                                               # Need to set ${MRB_PROJECT} to the master product
mrb newDev
source /home/<username>/FDEff/localProducts_larsoft_v08_62_01_e19_prof_py2/setup
# For example: source /home/wshi/FDEff/localProducts_larsoft_v08_62_01_e19_prof_py2/setup

cd srcs                            
git clone https://github.com/weishi10141993/myntuples.git                                # First time only, checkout the analysis code from GitHub
cp /home/wshi/dune/product_deps  /home/<username>/FDEff/srcs/myntuples/ups/product_deps  # Change version of larsoft, cetbuildtools, and qualifier list for dunetpc v08_62_01

mrb uc                                                                                   # Tell mrb to update CMakeLists.txt with the latest version numbers of the products.
cd ${MRB_BUILDDIR}                                                                       # Go to your build directory
mrb z
mrbsetenv                                                                                # Create the bookkeeping files needed to compile programs.
mrb install   

```

3. Log in to Ivy 
```
ssh -AY fyguo@ivy.physics.sunysb.edu       # Log my ivy account
passwd                                     # Reset my password
exit                                       # Quit ivy
```
