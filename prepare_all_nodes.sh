#!/bin/bash
 
yum -y install nc expect ed ntp dmidecode pciutils
yum -y install gcc gcc-c++ gmp-devel mpfr-devel unzip

# Create and set the hosts file like:
cat > /etc/hosts <<EOF 
127.0.0.1     localhost.localdomain    localhost
::1           localhost6.localdomain6  localhost6
 
10.211.55.200 gfcpp.localdomain  gfcpp

EOF

mkdir native

BASEDIR=/home/vagrant/native
VERSION=64bit_8214_b3879
cp /vagrant/Pivotal_GemFire_NativeClient_Linux_$VERSION.zip $BASEDIR
cd $BASEDIR
unzip Pivotal_GemFire_NativeClient_Linux_$VERSION.zip

cat >> /home/vagrant/.bash_profile <<EOF

export GFCPP=$BASEDIR/NativeClient_Linux_$VERSION
export PATH=\$GFCPP/bin:\$PATH
export LD_LIBRARY_PATH=\$GFCPP/lib:\$LD_LIBRARY_PATH

EOF



