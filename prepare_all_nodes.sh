#!/bin/bash
 
yum -y install nc expect ed ntp dmidecode pciutils
yum -y install gcc gcc-c++ gmp-devel mpfr-devel unzip

# Set timezone and run NTP (set to Europe - Amsterdam time).
/etc/init.d/ntpd stop; 
mv /etc/localtime /etc/localtime.bak; 
ln -s /usr/share/zoneinfo/Europe/Amsterdam /etc/localtime; 
/etc/init.d/ntpd start

# Create and set the hosts file like:
cat > /etc/hosts <<EOF 
127.0.0.1     localhost.localdomain    localhost
::1           localhost6.localdomain6  localhost6
 
10.211.55.200 gfcpp.localdomain  gfcpp

EOF

mkdir native

cp /vagrant/Pivotal_GemFire_NativeClient_Linux_64bit_8202_b3768.zip /home/vagrant/native
cd /home/vagrant/native
unzip Pivotal_GemFire_NativeClient_Linux_64bit_8202_b3768.zip

cat >> /home/vagrant/.bash_profile <<EOF

export GFCPP=/home/vagrant/native/NativeClient_Linux_64bit_8202_b3768
export PATH=\$GFCPP/bin:\$PATH
export LD_LIBRARY_PATH=\$GFCPP/lib:\$LD_LIBRARY_PATH

EOF



