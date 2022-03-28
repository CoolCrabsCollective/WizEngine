//
// Created by Alexander Winter on 2022-03-28.
//

#include <gtest/gtest.h>
#include "WIZ/input/MappingDatabase.h"

TEST(mapping, test_load_from_csv)
{
	wiz::MappingDatabase database;

#ifdef OS_WINDOWS
	database.loadFromCSV("03000000fa2d00000100000000000000,3dRudder Foot Motion Controller,leftx:a0,lefty:a1,rightx:a5,righty:a2,platform:Windows,\n"
						 "03000000d0160000040d000000000000,4Play Adapter,a:b1,b:b3,back:b4,dpdown:b11,dpleft:b12,dpright:b13,dpup:b10,leftshoulder:b6,leftstick:b14,lefttrigger:b8,leftx:a0,lefty:a1,rightshoulder:b7,rightstick:b15,righttrigger:b9,rightx:a3,righty:a4,start:b5,x:b0,y:b2,platform:Windows,\n"
						 "03000000d0160000050d000000000000,4Play Adapter,a:b1,b:b3,back:b4,dpdown:b11,dpleft:b12,dpright:b13,dpup:b10,leftshoulder:b6,leftstick:b14,lefttrigger:b8,leftx:a0,lefty:a1,rightshoulder:b7,rightstick:b15,righttrigger:b9,rightx:a3,righty:a4,start:b5,x:b0,y:b2,platform:Windows,\n"
						 "22000000000000000000000000000000,Test Controller,a:b2,b:b1,back:b8,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,leftshoulder:b4,leftstick:b10,lefttrigger:b6,leftx:a0,lefty:a1,rightshoulder:b5,rightstick:b11,righttrigger:b7,rightx:a2,righty:a3,start:b9,x:b3,y:b0,platform:Windows,\n"
						 "03000000d0160000060d000000000000,4Play Adapter,a:b1,b:b3,back:b4,dpdown:b11,dpleft:b12,dpright:b13,dpup:b10,leftshoulder:b6,leftstick:b14,lefttrigger:b8,leftx:a0,lefty:a1,rightshoulder:b7,rightstick:b15,righttrigger:b9,rightx:a3,righty:a4,start:b5,x:b0,y:b2,platform:Windows,\n"
						 "03000000d0160000070d000000000000,4Play Adapter,a:b1,b:b3,back:b4,dpdown:b11,dpleft:b12,dpright:b13,dpup:b10,leftshoulder:b6,leftstick:b14,lefttrigger:b8,leftx:a0,lefty:a1,rightshoulder:b7,rightstick:b15,righttrigger:b9,rightx:a3,righty:a4,start:b5,x:b0,y:b2,platform:Windows,\n"
						 "03000000d0160000600a000000000000,4Play Adapter,a:b1,b:b3,back:b4,dpdown:b11,dpleft:b12,dpright:b13,dpup:b10,leftshoulder:b6,leftstick:b14,lefttrigger:b8,leftx:a0,lefty:a1,rightshoulder:b7,rightstick:b15,righttrigger:b9,rightx:a3,righty:a4,start:b5,x:b0,y:b2,platform:Windows,");
#endif

#ifdef OS_UNIX
	database.loadFromCSV("03000000a30c00002500000011010000,Sega Genesis Mini 3B Controller,a:b2,b:b1,dpdown:+a4,dpleft:-a3,dpright:+a3,dpup:-a4,righttrigger:b5,start:b9,platform:Linux,\n"
						 "03000000790000001100000011010000,Sega Saturn,a:b1,b:b2,back:b8,dpdown:+a1,dpleft:-a0,dpright:+a0,dpup:-a1,leftshoulder:b6,lefttrigger:b7,rightshoulder:b5,righttrigger:b4,start:b9,x:b0,y:b3,platform:Linux,\n"
						 "03000000790000002201000011010000,Sega Saturn,a:b0,b:b1,back:b8,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,leftshoulder:b4,lefttrigger:b5,rightshoulder:b6,righttrigger:b7,start:b9,x:b2,y:b3,platform:Linux,\n"
						 "03000000b40400000a01000000010000,Sega Saturn,a:b0,b:b1,leftshoulder:b6,lefttrigger:b7,leftx:a0,lefty:a1,rightshoulder:b5,righttrigger:b2,start:b8,x:b3,y:b4,platform:Linux,\n"
						 "030000001f08000001e4000010010000,SFC Controller,a:b2,b:b1,back:b8,leftshoulder:b4,leftx:a0,lefty:a1,rightshoulder:b5,start:b9,x:b3,y:b0,platform:Linux,\n"
						 "03000000632500002305000010010000,ShanWan Gamepad,a:b2,b:b1,back:b8,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,leftshoulder:b4,leftstick:b10,lefttrigger:b6,leftx:a0,lefty:a1,rightshoulder:b5,rightstick:b11,righttrigger:b7,rightx:a2,righty:a3,start:b9,x:b3,y:b0,platform:Linux,\n"
						 "22000000000000000000000000000000,Test Controller,a:b2,b:b1,back:b8,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,leftshoulder:b4,leftstick:b10,lefttrigger:b6,leftx:a0,lefty:a1,rightshoulder:b5,rightstick:b11,righttrigger:b7,rightx:a2,righty:a3,start:b9,x:b3,y:b0,platform:Linux,\n"
						 "03000000f025000021c1000010010000,Shanwan Gioteck PS3 Controller,a:b2,b:b1,back:b8,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,leftshoulder:b4,leftstick:b10,lefttrigger:b6,leftx:a0,lefty:a1,rightshoulder:b5,rightstick:b11,righttrigger:b7,rightx:a2,righty:a3,start:b9,x:b3,y:b0,platform:Linux,\n"
						 "03000000632500007505000010010000,Shanwan PS3 PC,a:b2,b:b1,back:b8,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,guide:b12,leftshoulder:b4,leftstick:b10,lefttrigger:b6,leftx:a0,lefty:a1,rightshoulder:b5,rightstick:b11,righttrigger:b7,rightx:a2,righty:a3,start:b9,x:b3,y:b0,platform:Linux,\n"
						 "03000000bc2000000055000010010000,Shanwan PS3 PC ,a:b0,b:b1,back:b10,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,leftshoulder:b6,leftstick:b13,lefttrigger:a5,leftx:a0,lefty:a1,rightshoulder:b7,rightstick:b14,righttrigger:a4,rightx:a2,righty:a3,start:b11,x:b3,y:b4,platform:Linux,\n"
						 "030000005f140000c501000010010000,Shanwan Trust,a:b2,b:b1,back:b8,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,guide:b12,leftshoulder:b4,leftstick:b10,lefttrigger:b6,leftx:a0,lefty:a1,rightshoulder:b5,rightstick:b11,righttrigger:b7,rightx:a2,righty:a3,start:b9,x:b3,y:b0,platform:Linux,\n"
						 "03000000341a00000908000010010000,SL6566,a:b0,b:b1,back:b8,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,leftshoulder:b4,leftstick:b10,lefttrigger:b6,leftx:a0,lefty:a1,rightshoulder:b5,rightstick:b11,righttrigger:b7,rightx:a2,righty:a3,start:b9,x:b2,y:b3,platform:Linux,");
#endif

#ifdef OS_MAC
	database.loadFromCSV("030000004f04000015b3000000000000,Thrustmaster Dual Analog 3.2,a:b0,b:b2,back:b8,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,leftshoulder:b4,leftstick:b10,lefttrigger:b5,leftx:a0,lefty:a1,rightshoulder:b6,rightstick:b11,righttrigger:b7,rightx:a2,righty:a3,start:b9,x:b1,y:b3,platform:Mac OS X,\n"
						 "030000004f0400000ed0000000020000,ThrustMaster eSwap Pro Controller,a:b1,b:b2,back:b8,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,guide:b12,leftshoulder:b4,leftstick:b10,lefttrigger:a3,leftx:a0,lefty:a1,rightshoulder:b5,rightstick:b11,righttrigger:a4,rightx:a2,righty:a5,start:b9,x:b0,y:b3,platform:Mac OS X,\n"
						 "030000004f04000000b3000000000000,Thrustmaster Firestorm Dual Power,a:b0,b:b2,back:b9,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,guide:b8,leftshoulder:b4,leftstick:b11,lefttrigger:b5,leftx:a0,lefty:a1,rightshoulder:b6,righttrigger:b7,rightx:a2,righty:a3,start:b10,x:b1,y:b3,platform:Mac OS X,\n"
						 "03000000bd12000015d0000000010000,Tomee Retro Controller,a:b2,b:b1,back:b8,dpdown:+a1,dpleft:-a0,dpright:+a0,dpup:-a1,leftshoulder:b4,rightshoulder:b5,start:b9,x:b3,y:b0,platform:Mac OS X,\n"
						 "03000000bd12000015d0000000000000,Tomee SNES Controller,a:b2,b:b1,back:b8,dpdown:+a1,dpleft:-a0,dpright:+a0,dpup:-a1,leftshoulder:b4,rightshoulder:b5,start:b9,x:b3,y:b0,platform:Mac OS X,\n"
						 "22000000000000000000000000000000,Test Controller,a:b2,b:b1,back:b8,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,leftshoulder:b4,leftstick:b10,lefttrigger:b6,leftx:a0,lefty:a1,rightshoulder:b5,rightstick:b11,righttrigger:b7,rightx:a2,righty:a3,start:b9,x:b3,y:b0,platform:Mac OS X,\n"
						 "03000000100800000100000000000000,Twin USB Joystick,a:b4,b:b2,back:b16,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,leftshoulder:b12,leftstick:b20,lefttrigger:b8,leftx:a0,lefty:a2,rightshoulder:b14,rightstick:b22,righttrigger:b10,rightx:a6,righty:a4,start:b18,x:b6,y:b0,platform:Mac OS X,\n"
						 "030000006f0e00000302000025040000,Victrix PS4 Pro Fightstick,a:b1,b:b2,back:b8,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,guide:b12,leftshoulder:b4,lefttrigger:b6,rightshoulder:b5,righttrigger:b7,start:b9,x:b0,y:b3,platform:Mac OS X,\n"
						 "030000006f0e00000702000003060000,Victrix PS4 Pro Fightstick,a:b1,b:b2,back:b8,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,guide:b12,leftshoulder:b4,leftstick:b10,lefttrigger:b6,rightshoulder:b5,righttrigger:b7,start:b9,x:b0,y:b3,platform:Mac OS X,\n"
						 "050000005769696d6f74652028303000,Wii Remote,a:b4,b:b5,back:b7,dpdown:b3,dpleft:b0,dpright:b1,dpup:b2,guide:b8,leftshoulder:b11,lefttrigger:b12,leftx:a0,lefty:a1,start:b6,x:b10,y:b9,platform:Mac OS X,\n"
						 "050000005769696d6f74652028313800,Wii U Pro Controller,a:b16,b:b15,back:b7,dpdown:b12,dpleft:b13,dpright:b14,dpup:b11,guide:b8,leftshoulder:b19,leftstick:b23,lefttrigger:b21,leftx:a0,lefty:a1,rightshoulder:b20,rightstick:b24,righttrigger:b22,rightx:a2,righty:a3,start:b6,x:b18,y:b17,platform:Mac OS X,");
#endif

	ASSERT_TRUE(database.hasMapping("Test Controller"));

	wiz::Mapping mapping = database.getMapping("Test Controller");

	ASSERT_EQ(mapping.getButton(wiz::MapButton::A), 2);
	ASSERT_EQ(mapping.getButton(wiz::MapButton::B), 1);
	ASSERT_EQ(mapping.getButton(wiz::MapButton::X), 3);
	ASSERT_EQ(mapping.getButton(wiz::MapButton::Y), 0);
	ASSERT_EQ(mapping.getButton(wiz::MapButton::Back), 8);
	ASSERT_EQ(mapping.getButton(wiz::MapButton::Start), 9);

	ASSERT_EQ(mapping.getButton(wiz::MapButton::Left_Trigger), 6);
	ASSERT_EQ(mapping.getButton(wiz::MapButton::Right_Trigger), 7);

	ASSERT_EQ(mapping.getButton(wiz::MapButton::Left_Shoulder), 4);
	ASSERT_EQ(mapping.getButton(wiz::MapButton::Right_Shoulder), 5);

	ASSERT_EQ(mapping.getButton(wiz::MapButton::Left_Stick), 10);
	ASSERT_EQ(mapping.getButton(wiz::MapButton::Right_Stick), 11);
}