2016.05

Vagrant VM Setup for Native Labs
---


Prerequisites:
--------------

1. VirtualBox: https://www.virtualbox.org

2. Vagrant: https://www.vagrantup.com/downloads.html


Steps:

1. bring up the VM:

  $ vagrant up


Notes:
------

1. you can ssh into your guest OS with:

  $ vagrant ssh

2. All files in this directory are shared with your guest OS under the folder /vagrant

  $ cd /vagrant

  You'll see a copy of the native labs folder "labs/" in there.

  The fact that this folder is shared with both the host and guest OS
    implies that you have the convenience of editing the lab .cpp (and other) files on your host OS,
    while compiling the code on the guest OS.

3. Follow the instructions in "labinstructions.pdf" to complete the labs

4. You will need to know how to access gemfire (which is running on your host) from the guest OS.  This command, invoked on the guest should tell you what that IP address is:

  $ netstat -rn | grep '^0.0.0.0 ' | awk '{print $2}'

7. For convenience, if you have difficulty compiling Basic.cpp, here is the command:

  $ g++ -D_REENTRANT -O3 -Wall -m64 -I${GFCPP}/include -L${GFCPP}/lib -Wl,-rpath,${GFCPP}/lib -lgfcppcache Basic.cpp -o Basic


