# DUNE_PRISM
## I. Preparations 
> Instructions:  
> - https://github.com/weishi10141993/myntuples (DUNE_PRISM)   
> - https://indico.cern.ch/event/1058873/timetable/  (General Linux). 
1. [Create a SBU ivy account](https://docs.joyent.com/public-cloud/getting-started/ssh-keys/generating-an-ssh-key-manually)
2. Set up SBU ivy work area, copied from Dr. Wei Shi's Github (see Instructions)  
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
3. Log in to ivy 
```
ssh -AY fyguo@ivy.physics.sunysb.edu       # Log my ivy account
passwd                                     # Reset my password
exit                                       # Quit ivy
```
