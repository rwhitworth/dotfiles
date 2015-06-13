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
