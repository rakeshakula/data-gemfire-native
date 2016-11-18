# -*- mode: ruby -*-
# vi: set ft=ruby :

VAGRANTFILE_API_VERSION = "2"

VM_BOX = "bento/centos-6.7"

VM_MEMORY_MB = "1024"

Vagrant.configure(VAGRANTFILE_API_VERSION) do |config|

  VM_NAME = "gfcpp"
  
  config.vm.define VM_NAME do |gfcpp|

    gfcpp.vm.box = VM_BOX
      gfcpp.vm.provider :virtualbox do |v|
        v.name = VM_NAME
        v.customize ["modifyvm", :id, "--memory", VM_MEMORY_MB]
      end

      gfcpp.vm.hostname = "gfcpp.localdomain"
      gfcpp.vm.network :private_network, ip: "10.211.55.200"
      gfcpp.vm.network :forwarded_port, guest: 5443, host: 5443

      gfcpp.vm.provision "shell" do |s|
        s.path = "prepare_all_nodes.sh"
      end
    end
end
