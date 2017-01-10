# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure("2") do |config|

  config.vm.box = "bento/centos-7.2"

  config.vm.provider "virtualbox" do |vb|
    vb.memory = "2048"
  end

  config.vm.provision "shell", inline: <<-SHELL

    yum -y install nc expect ed ntp dmidecode pciutils
    yum -y install gcc gcc-c++ gmp-devel mpfr-devel unzip

    VAGRANT_HOME=/home/vagrant
    VERSION=64bit_8214_b3879

    unzip -o -d $VAGRANT_HOME /vagrant/Pivotal_GemFire_NativeClient_Linux_$VERSION.zip

    cat >> $VAGRANT_HOME/.bash_profile <<EOF

export GFCPP=$VAGRANT_HOME/NativeClient_Linux_$VERSION
export PATH=\\$GFCPP/bin:\\$PATH
export LD_LIBRARY_PATH=\\$GFCPP/lib:\\$LD_LIBRARY_PATH

set -o vi

EOF

  SHELL

end
