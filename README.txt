2016.05

Vagrant VM Setup for Native Labs
---


Prerequisites:
--------------

1. VirtualBox: https://www.virtualbox.org
2. Vagrant: https://www.vagrantup.com/downloads.html
3. Pre-install the CentOS Vagrant Box.  From the console window run:
  $ vagrant box add bento/centos-6.7 --provider virtualbox --box-version 2.2.6
4. to bring up the VM, run:
  $ vagrant up


Notes:
------

1. you can invoke this command to ssh into your guest OS:
  $ vagrant ssh
2. All files in this directory are shared with your guest OS under the folder /vagrant
  $ cd /vagrant
3. You'll see a copy of the native labs folder "labs/" in there.
4. Because this folder is shared with the host and guest OS, it means you have the convenience of editing the lab .cpp (and other) files using your host OS, but compile the code on the guest OS.
5. Follow the instructions in "labinstructions.pdf" to complete the labs
6. You will need to know how to access gemfire (which is running on your host) from the guest OS.  This command, invoked on the guest should tell you what that IP address is:
  $ netstat -rn | grep '^0.0.0.0 ' | awk '{print $2}'
7. For convenience, if you have difficulty compiling Basic.cpp, here is the command:
  $ g++ -D_REENTRANT -O3 -Wall -m64 -I${GFCPP}/include -L${GFCPP}/lib -Wl,-rpath,${GFCPP}/lib -lgfcppcache Basic.cpp -o Basic
