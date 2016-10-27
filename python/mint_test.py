#!/usr/bin/python
import sys
import string
import struct
import getopt
import time
from socket import *

class MINT_TESTER:
	def __init__(self, my_port = 0):
		try:
			self.s = socket(AF_MINT,SOCK_DGRAM)
			self.s.bind((5, my_port,))
		except error:
			print "bind failed"

	def send(self, to_map, to_port, pkt_size):
		# payload = "\x11\x22\x33"+"".zfill(pkt_size-6)+"\xaa\xbb\xcc"
		payload = "4D.15.E9.20"+"".zfill(pkt_size-6)+"\xaa\xbb\xcc"
		print "sending "+str(len(payload))+"bytes"
		self.s.sendto(payload, 0, (to_map, htons(to_port)))
		#self.s.sendto(payload,(0,to_port,0,"10.10.10.10"))
	
	def recv(self):
		data, address = self.s.recvfrom(1024)
		print "rx "+str(len(data))+"bytes of data"
	
def Usage(errstr=""):
	if errstr != "":
		print "** Error: " + errstr + "\n"
		print "testamint.py -s(0-65000) -c(1-9999) "
		print " -s -> payload size, from 0 to 65k"
		print " -c -> number of pkts to send 1-9999"
		print " -r -> block and receive"
		print ""
		sys.exit(1)


def str2id(txt):
    # """ convert text to a integer mint address """
    # we accept two form, both with an optional "0x" prefix
    #   [0x]HH.HH.HH.HH
    # and
    #   [0x]HHHHHHHH
    txt = txt.strip()
    # remove any leading "0x" prefix
    if txt[0:2] == '0x':
      txt = txt[2:]
    if txt.find('.') >= 0:
      x, = struct.unpack('>I', ''.join([chr(int(x,16)) for x in txt.split('.')]))
      return x
    if txt.find('-') >= 0:
      x, = struct.unpack('>I', ''.join([chr(int(x,16)) for x in txt.split('-')]))
      return x
    else:
      x = long(txt,16)
      return x

def main():

	print "[JK-Test-01] main : Begin --->"
	pkt_size = 64
	count = 1
	block_n_recv = 0
	my_port = 141
	try:
		(opts, args) = getopt.getopt(sys.argv[1:], "s:c:hr")
	except getopt.GetoptError, err:
		return Usage()
	
	if args:
		return Usage()
		
	for (opt, val) in opts:
		# python does not have a switch-case!!
		if opt == '-s':
			pkt_size = int(val);
		if opt == '-c':
			count = int(val);
		if opt == '-h':
			return Usage()
		if opt == '-r':
			block_n_recv = 1
	
	mt = MINT_TESTER(my_port)
	mint_addr = 0x20e9154d
	peer_id = str2id(mint_addr)
	print "[JK-Test-02] main : mint_addr = %s" %(mint_addr)
	print "[JK-Test-03] main : peer_id = %d" %(peer_id)

	if block_n_recv == 1:
		print "[JK-Test-04] main : Going to Rx now " 
		mt.recv()
	else:
		print "[JK-Test-04] main : Going to Tx now on Port[%d] " %(my_port) 
		for i in range(0,count):
			mt.send(peer_id, my_port, pkt_size)
			time.sleep(1)

if __name__ == '__main__':
		main()
