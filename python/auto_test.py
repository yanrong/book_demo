import uiautomator2 as u2
import random
from time import sleep

random_dial = []
class_name = "com.android.dialer"
tap_pos = [[240, 670], [110, 400], [240, 390], [380, 400], [110, 500], [240, 500],
 [380, 500], [110, 600], [240, 600], [380, 600], [110, 680], [380, 660]]

def gen_random_dial():
	dial_list = []
	i = 0;
	while(i < 11):
		dial_list.append(random.randint(0,11))
		i = i + 1
	
	return dial_list

def touch_tap(seq_list, dev):
	i = 0;
	for i in seq_list:
		dev.click(tap_pos[i][0], tap_pos[i][1])
		if i < 10:
			print "key", i
		elif i == 10:
			print "key *"
		else:
			print "key #"
	
	dev.long_click(440, 270, 1)
def de_offline(dev):
	settings = ''
	#dev.

def main():
	# 
	serial = '6c8a1316'
	dev = u2.connect_usb(serial)

	oninfo = d.info.get('screenOn')
	if oninfo == False:
		d.screen_on()
		sleep(1)
		d.press('home')
		print oninfo

	dial_session = dev.session(class_name)
	dev(resourceId="com.android.dialer:id/floating_action_button", 
		description=u"key pad", className="android.widget.ImageButton").click()
	sleep(0.5)
	while True:
		random_dial = gen_random_dial();
		touch_tap(random_dial, dev)
		sleep(2)
	

if __name__ == '__main__':
 	main()
