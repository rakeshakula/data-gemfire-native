
Vagrant.configure(2) do |config|

  config.vm.define "gfcpp" do |gfcpp|

    gfcpp.vm.box = "bento/centos-6.7"
      gfcpp.vm.provider :virtualbox do |v|
        v.name = "gfcpp"
        v.customize ["modifyvm", :id, "--memory", "1024"]
      end

      gfcpp.vm.hostname = "gfcpp.localdomain"
      gfcpp.vm.network :private_network, ip: "10.211.55.200"
      gfcpp.vm.network :forwarded_port, guest: 5443, host: 5443

      gfcpp.vm.provision "shell" do |s|
        s.path = "prepare_all_nodes.sh"
      end
    end
end
