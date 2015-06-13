# Creative Commons code
#
# This work is licensed under the 
# Creative Commons Attribution-ShareAlike 3.0 Unported License. 
# To view a copy of this license, visit 
# http://creativecommons.org/licenses/by-sa/3.0/ 
# or send a letter to 
# Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.

# compare version strings
#
# SOURCE: http://stackoverflow.com/questions/4023830/bash-how-compare-two-strings-in-version-format
#
# requires:
#  $1,$2	strings to compare
#
# returns:
#  0	if the versions match
#  1	if $1 > $2
#  2	if $2 > $1
#
function compare_version {
  if [[ $1 == $2 ]]; then return 0; fi
  local IFS=.
  local i ver1=($1) ver2=($2)
  # fill empty fields in ver1 with zeros
  for ((i=${#ver1[@]}; i<${#ver2[@]}; i++)); do ver1[i]=0; done
  for ((i=0; i<${#ver1[@]}; i++)); do
    if [[ -z ${ver2[i]} ]]; then
      # fill empty fields in ver2 with zeros
      ver2[i]=0
    fi
    if ((10#${ver1[i]} > 10#${ver2[i]})); then return 1; fi
    if ((10#${ver1[i]} < 10#${ver2[i]})); then return 2; fi
  done
  return 0
}

# get the network address for a given ip and subnet mask
#
# SOURCE:
# http://stackoverflow.com/questions/15429420/given-the-ip-and-netmask-how-can-i-calculate-the-network-address-using-bash
#
# This is completely equivilent to `ipcalc -n $1 $2`, but that is not
#   necessarily available on all operating systems.
#
# required:
#   $1  ip address
#   $2  subnet mask
#
function get_network {
  test $# -eq 2 || return 1
  valid_ip $1 || return 1
  local J="$2"
  test "$2" == "${2/[^0-9]/}" && J=$( cdr2mask $2 )
  IFS=. read -r i1 i2 i3 i4 <<< "$1"
  IFS=. read -r m1 m2 m3 m4 <<< "$J"
  printf "%d.%d.%d.%d\n" "$((i1 & m1))" "$(($i2 & m2))" "$((i3 & m3))" "$((i4 & m4))"
  return 0
}
