/**
  ******************************************************************************
  * @file    LED_CUBE.c
  * $Author: SFZ $
  * $Revision: 1 $
  * $Date:: 2018-11-27 16:16:48 +0800 #$
  * @brief   LED_CUBE显示函数.
  ******************************************************************************
  * @attention
  *
  * 
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "LED_CUBE.h"	

/* Private variables ---------------------------------------------------------*/
static unsigned char index_level = 1;
	const char* cube[499] = {"0:CUB1.txt","0:CUB2.txt","0:CUB3.txt","0:CUB4.txt","0:CUB5.txt",
												   "0:CUB6.txt","0:CUB7.txt","0:CUB8.txt","0:CUB9.txt","0:CUB10.txt",
												   "0:CUB11.txt","0:CUB12.txt","0:CUB13.txt","0:CUB14.txt","0:CUB15.txt",
												   "0:CUB16.txt","0:CUB17.txt","0:CUB18.txt","0:CUB19.txt","0:CUB20.txt",
												   "0:CUB21.txt","0:CUB22.txt","0:CUB23.txt","0:CUB24.txt","0:CUB25.txt",
												   "0:CUB26.txt","0:CUB27.txt","0:CUB28.txt","0:CUB29.txt","0:CUB30.txt",
												   "0:CUB31.txt","0:CUB32.txt","0:CUB33.txt","0:CUB34.txt","0:CUB35.txt",
												   "0:CUB36.txt","0:CUB37.txt","0:CUB38.txt","0:CUB39.txt","0:CUB40.txt",
												   "0:CUB41.txt","0:CUB42.txt","0:CUB43.txt","0:CUB44.txt","0:CUB45.txt",
												   "0:CUB46.txt","0:CUB47.txt","0:CUB48.txt","0:CUB49.txt","0:CUB50.txt",
												   "0:CUB51.txt","0:CUB52.txt","0:CUB53.txt","0:CUB54.txt","0:CUB55.txt",
												   "0:CUB56.txt","0:CUB57.txt","0:CUB58.txt","0:CUB59.txt","0:CUB60.txt",
												   "0:CUB61.txt","0:CUB62.txt","0:CUB63.txt","0:CUB64.txt","0:CUB65.txt",
												   "0:CUB66.txt","0:CUB67.txt","0:CUB68.txt","0:CUB69.txt","0:CUB70.txt",
												   "0:CUB71.txt","0:CUB72.txt","0:CUB73.txt","0:CUB74.txt","0:CUB75.txt",
												   "0:CUB76.txt","0:CUB77.txt","0:CUB78.txt","0:CUB79.txt","0:CUB80.txt",
												   "0:CUB81.txt","0:CUB82.txt","0:CUB83.txt","0:CUB84.txt","0:CUB85.txt",
												   "0:CUB86.txt","0:CUB87.txt","0:CUB88.txt","0:CUB89.txt","0:CUB90.txt",
													 "0:CUB91.txt","0:CUB92.txt","0:CUB93.txt","0:CUB94.txt","0:CUB95.txt",
												   "0:CUB96.txt","0:CUB97.txt","0:CUB98.txt","0:CUB99.txt","0:CUB100.txt",
													 "0:CUB101.txt","0:CUB102.txt","0:CUB103.txt","0:CUB104.txt","0:CUB105.txt",
												   "0:CUB106.txt","0:CUB107.txt","0:CUB108.txt","0:CUB109.txt","0:CUB110.txt",
												   "0:CUB111.txt","0:CUB112.txt","0:CUB113.txt","0:CUB114.txt","0:CUB115.txt",
												   "0:CUB116.txt","0:CUB117.txt","0:CUB118.txt","0:CUB119.txt","0:CUB120.txt",
												   "0:CUB121.txt","0:CUB122.txt","0:CUB123.txt","0:CUB124.txt","0:CUB125.txt",
												   "0:CUB126.txt","0:CUB127.txt","0:CUB128.txt","0:CUB129.txt","0:CUB130.txt",
												   "0:CUB131.txt","0:CUB132.txt","0:CUB133.txt","0:CUB134.txt","0:CUB135.txt",
												   "0:CUB136.txt","0:CUB137.txt","0:CUB138.txt","0:CUB139.txt","0:CUB140.txt",
												   "0:CUB141.txt","0:CUB142.txt","0:CUB143.txt","0:CUB144.txt","0:CUB145.txt",
												   "0:CUB146.txt","0:CUB147.txt","0:CUB148.txt","0:CUB149.txt","0:CUB150.txt",
												   "0:CUB151.txt","0:CUB152.txt","0:CUB153.txt","0:CUB154.txt","0:CUB155.txt",
												   "0:CUB156.txt","0:CUB157.txt","0:CUB158.txt","0:CUB159.txt","0:CUB160.txt",
												   "0:CUB161.txt","0:CUB162.txt","0:CUB163.txt","0:CUB164.txt","0:CUB165.txt",
												   "0:CUB166.txt","0:CUB167.txt","0:CUB168.txt","0:CUB169.txt","0:CUB170.txt",
												   "0:CUB171.txt","0:CUB172.txt","0:CUB173.txt","0:CUB174.txt","0:CUB175.txt",
												   "0:CUB176.txt","0:CUB177.txt","0:CUB178.txt","0:CUB179.txt","0:CUB180.txt",
												   "0:CUB181.txt","0:CUB182.txt","0:CUB183.txt","0:CUB184.txt","0:CUB185.txt",
												   "0:CUB186.txt","0:CUB187.txt","0:CUB188.txt","0:CUB189.txt","0:CUB190.txt",
													 "0:CUB191.txt","0:CUB192.txt","0:CUB193.txt","0:CUB194.txt","0:CUB195.txt",
												   "0:CUB196.txt","0:CUB197.txt","0:CUB198.txt","0:CUB199.txt","0:CUB200.txt",
													 "0:CUB201.txt","0:CUB202.txt","0:CUB203.txt","0:CUB204.txt","0:CUB205.txt",
												   "0:CUB206.txt","0:CUB207.txt","0:CUB208.txt","0:CUB209.txt","0:CUB210.txt",
												   "0:CUB211.txt","0:CUB212.txt","0:CUB213.txt","0:CUB214.txt","0:CUB215.txt",
												   "0:CUB216.txt","0:CUB217.txt","0:CUB218.txt","0:CUB219.txt","0:CUB220.txt",
												   "0:CUB221.txt","0:CUB222.txt","0:CUB223.txt","0:CUB224.txt","0:CUB225.txt",
												   "0:CUB226.txt","0:CUB227.txt","0:CUB228.txt","0:CUB229.txt","0:CUB230.txt",
												   "0:CUB231.txt","0:CUB232.txt","0:CUB233.txt","0:CUB234.txt","0:CUB235.txt",
												   "0:CUB236.txt","0:CUB237.txt","0:CUB238.txt","0:CUB239.txt","0:CUB240.txt",
												   "0:CUB241.txt","0:CUB242.txt","0:CUB243.txt","0:CUB244.txt","0:CUB245.txt",
												   "0:CUB246.txt","0:CUB247.txt","0:CUB248.txt","0:CUB249.txt","0:CUB250.txt",
												   "0:CUB251.txt","0:CUB252.txt","0:CUB253.txt","0:CUB254.txt","0:CUB255.txt",
												   "0:CUB256.txt","0:CUB257.txt","0:CUB258.txt","0:CUB259.txt","0:CUB260.txt",
												   "0:CUB261.txt","0:CUB262.txt","0:CUB263.txt","0:CUB264.txt","0:CUB265.txt",
												   "0:CUB266.txt","0:CUB267.txt","0:CUB268.txt","0:CUB269.txt","0:CUB270.txt",
												   "0:CUB271.txt","0:CUB272.txt","0:CUB273.txt","0:CUB274.txt","0:CUB275.txt",
												   "0:CUB276.txt","0:CUB277.txt","0:CUB278.txt","0:CUB279.txt","0:CUB280.txt",
												   "0:CUB281.txt","0:CUB282.txt","0:CUB283.txt","0:CUB284.txt","0:CUB285.txt",
												   "0:CUB286.txt","0:CUB287.txt","0:CUB288.txt","0:CUB289.txt","0:CUB290.txt",
													 "0:CUB291.txt","0:CUB292.txt","0:CUB293.txt","0:CUB294.txt","0:CUB295.txt",
												   "0:CUB296.txt","0:CUB297.txt","0:CUB298.txt","0:CUB299.txt","0:CUB300.txt",
													 "0:CUB301.txt","0:CUB302.txt","0:CUB303.txt","0:CUB304.txt","0:CUB305.txt",
												   "0:CUB306.txt","0:CUB307.txt","0:CUB308.txt","0:CUB309.txt","0:CUB310.txt",
												   "0:CUB311.txt","0:CUB312.txt","0:CUB313.txt","0:CUB314.txt","0:CUB315.txt",
												   "0:CUB316.txt","0:CUB317.txt","0:CUB318.txt","0:CUB319.txt","0:CUB320.txt",
												   "0:CUB321.txt","0:CUB322.txt","0:CUB323.txt","0:CUB324.txt","0:CUB325.txt",
												   "0:CUB326.txt","0:CUB327.txt","0:CUB328.txt","0:CUB329.txt","0:CUB330.txt",
												   "0:CUB331.txt","0:CUB332.txt","0:CUB333.txt","0:CUB334.txt","0:CUB335.txt",
												   "0:CUB336.txt","0:CUB337.txt","0:CUB338.txt","0:CUB339.txt","0:CUB340.txt",
												   "0:CUB341.txt","0:CUB342.txt","0:CUB343.txt","0:CUB344.txt","0:CUB345.txt",
												   "0:CUB346.txt","0:CUB347.txt","0:CUB348.txt","0:CUB349.txt","0:CUB350.txt",
												   "0:CUB351.txt","0:CUB352.txt","0:CUB353.txt","0:CUB354.txt","0:CUB355.txt",
												   "0:CUB356.txt","0:CUB357.txt","0:CUB358.txt","0:CUB359.txt","0:CUB360.txt",
												   "0:CUB361.txt","0:CUB362.txt","0:CUB363.txt","0:CUB364.txt","0:CUB365.txt",
												   "0:CUB366.txt","0:CUB367.txt","0:CUB368.txt","0:CUB369.txt","0:CUB370.txt",
												   "0:CUB371.txt","0:CUB372.txt","0:CUB373.txt","0:CUB374.txt","0:CUB375.txt",
												   "0:CUB376.txt","0:CUB377.txt","0:CUB378.txt","0:CUB379.txt","0:CUB380.txt",
												   "0:CUB381.txt","0:CUB382.txt","0:CUB383.txt","0:CUB384.txt","0:CUB385.txt",
												   "0:CUB386.txt","0:CUB387.txt","0:CUB388.txt","0:CUB389.txt","0:CUB390.txt",
													 "0:CUB391.txt","0:CUB392.txt","0:CUB393.txt","0:CUB394.txt","0:CUB395.txt",
												   "0:CUB396.txt","0:CUB397.txt","0:CUB398.txt","0:CUB399.txt","0:CUB400.txt",
													 "0:CUB401.txt","0:CUB402.txt","0:CUB403.txt","0:CUB404.txt","0:CUB405.txt",
												   "0:CUB406.txt","0:CUB407.txt","0:CUB408.txt","0:CUB409.txt","0:CUB410.txt",
												   "0:CUB411.txt","0:CUB412.txt","0:CUB413.txt","0:CUB414.txt","0:CUB415.txt",
												   "0:CUB416.txt","0:CUB417.txt","0:CUB418.txt","0:CUB419.txt","0:CUB420.txt",
												   "0:CUB421.txt","0:CUB422.txt","0:CUB423.txt","0:CUB424.txt","0:CUB425.txt",
												   "0:CUB426.txt","0:CUB427.txt","0:CUB428.txt","0:CUB429.txt","0:CUB430.txt",
												   "0:CUB431.txt","0:CUB432.txt","0:CUB433.txt","0:CUB434.txt","0:CUB435.txt",
												   "0:CUB436.txt","0:CUB437.txt","0:CUB438.txt","0:CUB439.txt","0:CUB440.txt",
												   "0:CUB441.txt","0:CUB442.txt","0:CUB443.txt","0:CUB444.txt","0:CUB445.txt",
												   "0:CUB446.txt","0:CUB447.txt","0:CUB448.txt","0:CUB449.txt","0:CUB450.txt",
												   "0:CUB451.txt","0:CUB452.txt","0:CUB453.txt","0:CUB454.txt","0:CUB455.txt",
												   "0:CUB456.txt","0:CUB457.txt","0:CUB458.txt","0:CUB459.txt","0:CUB460.txt",
												   "0:CUB461.txt","0:CUB462.txt","0:CUB463.txt","0:CUB464.txt","0:CUB465.txt",
												   "0:CUB466.txt","0:CUB467.txt","0:CUB468.txt","0:CUB469.txt","0:CUB470.txt",
												   "0:CUB471.txt","0:CUB472.txt","0:CUB473.txt","0:CUB474.txt","0:CUB475.txt",
												   "0:CUB476.txt","0:CUB477.txt","0:CUB478.txt","0:CUB479.txt","0:CUB480.txt",
												   "0:CUB481.txt","0:CUB482.txt","0:CUB483.txt","0:CUB484.txt","0:CUB485.txt",
												   "0:CUB486.txt","0:CUB487.txt","0:CUB488.txt","0:CUB489.txt","0:CUB490.txt",
													 "0:CUB491.txt","0:CUB492.txt","0:CUB493.txt","0:CUB494.txt","0:CUB495.txt",
												   "0:CUB496.txt","0:CUB497.txt","0:CUB498.txt","0:CUB499.txt"
												};
	
	const char* spiral[198]={"0:SPI1.txt","0:SPI2.txt","0:SPI3.txt","0:SPI4.txt","0:SPI5.txt",
													 "0:SPI6.txt","0:SPI7.txt","0:SPI8.txt","0:SPI9.txt","0:SPI10.txt",
													 "0:SPI11.txt","0:SPI12.txt","0:SPI13.txt","0:SPI14.txt","0:SPI15.txt",
													 "0:SPI16.txt","0:SPI17.txt","0:SPI18.txt","0:SPI19.txt","0:SPI20.txt",
													 "0:SPI21.txt","0:SPI22.txt","0:SPI23.txt","0:SPI24.txt","0:SPI25.txt",
													 "0:SPI26.txt","0:SPI27.txt","0:SPI28.txt","0:SPI29.txt","0:SPI30.txt",
													 "0:SPI31.txt","0:SPI32.txt","0:SPI33.txt","0:SPI34.txt","0:SPI35.txt",
													 "0:SPI36.txt","0:SPI37.txt","0:SPI38.txt","0:SPI39.txt","0:SPI40.txt",
													 "0:SPI41.txt","0:SPI42.txt","0:SPI43.txt","0:SPI44.txt","0:SPI45.txt",
													 "0:SPI46.txt","0:SPI47.txt","0:SPI48.txt","0:SPI49.txt","0:SPI50.txt",
													 "0:SPI51.txt","0:SPI52.txt","0:SPI53.txt","0:SPI54.txt","0:SPI55.txt",
													 "0:SPI56.txt","0:SPI57.txt","0:SPI58.txt","0:SPI59.txt","0:SPI60.txt",
													 "0:SPI61.txt","0:SPI62.txt","0:SPI63.txt","0:SPI64.txt","0:SPI65.txt",
													 "0:SPI66.txt","0:SPI67.txt","0:SPI68.txt","0:SPI69.txt","0:SPI70.txt",
													 "0:SPI71.txt","0:SPI72.txt","0:SPI73.txt","0:SPI74.txt","0:SPI75.txt",
													 "0:SPI76.txt","0:SPI77.txt","0:SPI78.txt","0:SPI79.txt","0:SPI80.txt",
													 "0:SPI81.txt","0:SPI82.txt","0:SPI83.txt","0:SPI84.txt","0:SPI85.txt",
													 "0:SPI86.txt","0:SPI87.txt","0:SPI88.txt","0:SPI89.txt","0:SPI90.txt",
													 "0:SPI91.txt","0:SPI92.txt","0:SPI93.txt","0:SPI94.txt","0:SPI95.txt",
													 "0:SPI96.txt","0:SPI97.txt","0:SPI98.txt","0:SPI99.txt","0:SPI100.txt",
													 "0:SPI101.txt","0:SPI102.txt","0:SPI103.txt","0:SPI104.txt","0:SPI105.txt",
													 "0:SPI106.txt","0:SPI107.txt","0:SPI108.txt","0:SPI109.txt","0:SPI110.txt",
													 "0:SPI111.txt","0:SPI112.txt","0:SPI113.txt","0:SPI114.txt","0:SPI115.txt",
													 "0:SPI116.txt","0:SPI117.txt","0:SPI118.txt","0:SPI119.txt","0:SPI120.txt",
													 "0:SPI121.txt","0:SPI122.txt","0:SPI123.txt","0:SPI124.txt","0:SPI125.txt",
													 "0:SPI126.txt","0:SPI127.txt","0:SPI128.txt","0:SPI129.txt","0:SPI130.txt",
													 "0:SPI131.txt","0:SPI132.txt","0:SPI133.txt","0:SPI134.txt","0:SPI135.txt",
													 "0:SPI136.txt","0:SPI137.txt","0:SPI138.txt","0:SPI139.txt","0:SPI140.txt",
													 "0:SPI141.txt","0:SPI142.txt","0:SPI143.txt","0:SPI144.txt","0:SPI145.txt",
													 "0:SPI146.txt","0:SPI147.txt","0:SPI148.txt","0:SPI149.txt","0:SPI150.txt",
													 "0:SPI151.txt","0:SPI152.txt","0:SPI153.txt","0:SPI154.txt","0:SPI155.txt",
													 "0:SPI156.txt","0:SPI157.txt","0:SPI158.txt","0:SPI159.txt","0:SPI160.txt",
													 "0:SPI161.txt","0:SPI162.txt","0:SPI163.txt","0:SPI164.txt","0:SPI165.txt",
													 "0:SPI166.txt","0:SPI167.txt","0:SPI168.txt","0:SPI169.txt","0:SPI170.txt",
													 "0:SPI171.txt","0:SPI172.txt","0:SPI173.txt","0:SPI174.txt","0:SPI175.txt",
													 "0:SPI176.txt","0:SPI177.txt","0:SPI178.txt","0:SPI179.txt","0:SPI180.txt",
													 "0:SPI181.txt","0:SPI182.txt","0:SPI183.txt","0:SPI184.txt","0:SPI185.txt",
													 "0:SPI186.txt","0:SPI187.txt","0:SPI188.txt","0:SPI189.txt","0:SPI190.txt",
													 "0:SPI191.txt","0:SPI192.txt","0:SPI193.txt","0:SPI194.txt","0:SPI195.txt",
													 "0:SPI196.txt","0:SPI197.txt","0:SPI198.txt"
	};
	
	
	const char* swirls[264]={"0:swi1.txt","0:swi2.txt","0:swi3.txt","0:swi4.txt","0:swi5.txt",
													 "0:swi6.txt","0:swi7.txt","0:swi8.txt","0:swi9.txt","0:swi10.txt",
													 "0:swi11.txt","0:swi12.txt","0:swi13.txt","0:swi14.txt","0:swi15.txt",
													 "0:swi16.txt","0:swi17.txt","0:swi18.txt","0:swi19.txt","0:swi20.txt",
													 "0:swi21.txt","0:swi22.txt","0:swi23.txt","0:swi24.txt","0:swi25.txt",
													 "0:swi26.txt","0:swi27.txt","0:swi28.txt","0:swi29.txt","0:swi30.txt",
													 "0:swi31.txt","0:swi32.txt","0:swi33.txt","0:swi34.txt","0:swi35.txt",
													 "0:swi36.txt","0:swi37.txt","0:swi38.txt","0:swi39.txt","0:swi40.txt",
													 "0:swi41.txt","0:swi42.txt","0:swi43.txt","0:swi44.txt","0:swi45.txt",
													 "0:swi46.txt","0:swi47.txt","0:swi48.txt","0:swi49.txt","0:swi50.txt",
													 "0:swi51.txt","0:swi52.txt","0:swi53.txt","0:swi54.txt","0:swi55.txt",
													 "0:swi56.txt","0:swi57.txt","0:swi58.txt","0:swi59.txt","0:swi60.txt",
													 "0:swi61.txt","0:swi62.txt","0:swi63.txt","0:swi64.txt","0:swi65.txt",
													 "0:swi66.txt","0:swi67.txt","0:swi68.txt","0:swi69.txt","0:swi70.txt",
													 "0:swi71.txt","0:swi72.txt","0:swi73.txt","0:swi74.txt","0:swi75.txt",
													 "0:swi76.txt","0:swi77.txt","0:swi78.txt","0:swi79.txt","0:swi80.txt",
													 "0:swi81.txt","0:swi82.txt","0:swi83.txt","0:swi84.txt","0:swi85.txt",
													 "0:swi86.txt","0:swi87.txt","0:swi88.txt","0:swi89.txt","0:swi90.txt",
													 "0:swi91.txt","0:swi92.txt","0:swi93.txt","0:swi94.txt","0:swi95.txt",
													 "0:swi96.txt","0:swi97.txt","0:swi98.txt","0:swi99.txt","0:swi100.txt",
													 "0:swi101.txt","0:swi102.txt","0:swi103.txt","0:swi104.txt","0:swi105.txt",
													 "0:swi106.txt","0:swi107.txt","0:swi108.txt","0:swi109.txt","0:swi110.txt",
													 "0:swi111.txt","0:swi112.txt","0:swi113.txt","0:swi114.txt","0:swi115.txt",
													 "0:swi116.txt","0:swi117.txt","0:swi118.txt","0:swi119.txt","0:swi120.txt",
													 "0:swi121.txt","0:swi122.txt","0:swi123.txt","0:swi124.txt","0:swi125.txt",
													 "0:swi126.txt","0:swi127.txt","0:swi128.txt","0:swi129.txt","0:swi130.txt",
													 "0:swi131.txt","0:swi132.txt","0:swi133.txt","0:swi134.txt","0:swi135.txt",
													 "0:swi136.txt","0:swi137.txt","0:swi138.txt","0:swi139.txt","0:swi140.txt",
													 "0:swi141.txt","0:swi142.txt","0:swi143.txt","0:swi144.txt","0:swi145.txt",
													 "0:swi146.txt","0:swi147.txt","0:swi148.txt","0:swi149.txt","0:swi150.txt",
													 "0:swi151.txt","0:swi152.txt","0:swi153.txt","0:swi154.txt","0:swi155.txt",
													 "0:swi156.txt","0:swi157.txt","0:swi158.txt","0:swi159.txt","0:swi160.txt",
													 "0:swi161.txt","0:swi162.txt","0:swi163.txt","0:swi164.txt","0:swi165.txt",
													 "0:swi166.txt","0:swi167.txt","0:swi168.txt","0:swi169.txt","0:swi170.txt",
													 "0:swi171.txt","0:swi172.txt","0:swi173.txt","0:swi174.txt","0:swi175.txt",
													 "0:swi176.txt","0:swi177.txt","0:swi178.txt","0:swi179.txt","0:swi180.txt",
													 "0:swi181.txt","0:swi182.txt","0:swi183.txt","0:swi184.txt","0:swi185.txt",
													 "0:swi186.txt","0:swi187.txt","0:swi188.txt","0:swi189.txt","0:swi190.txt",
													 "0:swi191.txt","0:swi192.txt","0:swi193.txt","0:swi194.txt","0:swi195.txt",
													 "0:swi196.txt","0:swi197.txt","0:swi198.txt","0:swi199.txt","0:swi200.txt",
													 "0:swi201.txt","0:swi202.txt","0:swi203.txt","0:swi204.txt","0:swi205.txt",
													 "0:swi206.txt","0:swi207.txt","0:swi208.txt","0:swi209.txt","0:swi210.txt",
													 "0:swi211.txt","0:swi212.txt","0:swi213.txt","0:swi214.txt","0:swi215.txt",
													 "0:swi216.txt","0:swi217.txt","0:swi218.txt","0:swi219.txt","0:swi220.txt",
													 "0:swi221.txt","0:swi222.txt","0:swi223.txt","0:swi224.txt","0:swi225.txt",
													 "0:swi226.txt","0:swi227.txt","0:swi228.txt","0:swi229.txt","0:swi230.txt",
													 "0:swi231.txt","0:swi232.txt","0:swi233.txt","0:swi234.txt","0:swi235.txt",
													 "0:swi236.txt","0:swi237.txt","0:swi238.txt","0:swi239.txt","0:swi240.txt",
													 "0:swi241.txt","0:swi242.txt","0:swi243.txt","0:swi244.txt","0:swi245.txt",
													 "0:swi246.txt","0:swi247.txt","0:swi248.txt","0:swi249.txt","0:swi250.txt",
													 "0:swi251.txt","0:swi252.txt","0:swi253.txt","0:swi254.txt","0:swi255.txt",
													 "0:swi256.txt","0:swi257.txt","0:swi258.txt","0:swi259.txt","0:swi260.txt",
													 "0:swi261.txt","0:swi262.txt","0:swi263.txt","0:swi264.txt"
	};
	
	const char* ripple[192]={"0:rip1.txt","0:rip2.txt","0:rip3.txt","0:rip4.txt","0:rip5.txt",
													 "0:rip6.txt","0:rip7.txt","0:rip8.txt","0:rip9.txt","0:rip10.txt",
													 "0:rip11.txt","0:rip12.txt","0:rip13.txt","0:rip14.txt","0:rip15.txt",
													 "0:rip16.txt","0:rip17.txt","0:rip18.txt","0:rip19.txt","0:rip20.txt",
													 "0:rip21.txt","0:rip22.txt","0:rip23.txt","0:rip24.txt","0:rip25.txt",
													 "0:rip26.txt","0:rip27.txt","0:rip28.txt","0:rip29.txt","0:rip30.txt",
													 "0:rip31.txt","0:rip32.txt","0:rip33.txt","0:rip34.txt","0:rip35.txt",
													 "0:rip36.txt","0:rip37.txt","0:rip38.txt","0:rip39.txt","0:rip40.txt",
													 "0:rip41.txt","0:rip42.txt","0:rip43.txt","0:rip44.txt","0:rip45.txt",
													 "0:rip46.txt","0:rip47.txt","0:rip48.txt","0:rip49.txt","0:rip50.txt",
													 "0:rip51.txt","0:rip52.txt","0:rip53.txt","0:rip54.txt","0:rip55.txt",
													 "0:rip56.txt","0:rip57.txt","0:rip58.txt","0:rip59.txt","0:rip60.txt",
													 "0:rip61.txt","0:rip62.txt","0:rip63.txt","0:rip64.txt","0:rip65.txt",
													 "0:rip66.txt","0:rip67.txt","0:rip68.txt","0:rip69.txt","0:rip70.txt",
													 "0:rip71.txt","0:rip72.txt","0:rip73.txt","0:rip74.txt","0:rip75.txt",
													 "0:rip76.txt","0:rip77.txt","0:rip78.txt","0:rip79.txt","0:rip80.txt",
													 "0:rip81.txt","0:rip82.txt","0:rip83.txt","0:rip84.txt","0:rip85.txt",
													 "0:rip86.txt","0:rip87.txt","0:rip88.txt","0:rip89.txt","0:rip90.txt",
													 "0:rip91.txt","0:rip92.txt","0:rip93.txt","0:rip94.txt","0:rip95.txt",
													 "0:rip96.txt","0:rip97.txt","0:rip98.txt","0:rip99.txt","0:rip100.txt",
													 "0:rip101.txt","0:rip102.txt","0:rip103.txt","0:rip104.txt","0:rip105.txt",
													 "0:rip106.txt","0:rip107.txt","0:rip108.txt","0:rip109.txt","0:rip110.txt",
													 "0:rip111.txt","0:rip112.txt","0:rip113.txt","0:rip114.txt","0:rip115.txt",
													 "0:rip116.txt","0:rip117.txt","0:rip118.txt","0:rip119.txt","0:rip120.txt",
													 "0:rip121.txt","0:rip122.txt","0:rip123.txt","0:rip124.txt","0:rip125.txt",
													 "0:rip126.txt","0:rip127.txt","0:rip128.txt","0:rip129.txt","0:rip130.txt",
													 "0:rip131.txt","0:rip132.txt","0:rip133.txt","0:rip134.txt","0:rip135.txt",
													 "0:rip136.txt","0:rip137.txt","0:rip138.txt","0:rip139.txt","0:rip140.txt",
													 "0:rip141.txt","0:rip142.txt","0:rip143.txt","0:rip144.txt","0:rip145.txt",
													 "0:rip146.txt","0:rip147.txt","0:rip148.txt","0:rip149.txt","0:rip150.txt",
													 "0:rip151.txt","0:rip152.txt","0:rip153.txt","0:rip154.txt","0:rip155.txt",
													 "0:rip156.txt","0:rip157.txt","0:rip158.txt","0:rip159.txt","0:rip160.txt",
													 "0:rip161.txt","0:rip162.txt","0:rip163.txt","0:rip164.txt","0:rip165.txt",
													 "0:rip166.txt","0:rip167.txt","0:rip168.txt","0:rip169.txt","0:rip170.txt",
													 "0:rip171.txt","0:rip172.txt","0:rip173.txt","0:rip174.txt","0:rip175.txt",
													 "0:rip176.txt","0:rip177.txt","0:rip178.txt","0:rip179.txt","0:rip180.txt",
													 "0:rip181.txt","0:rip182.txt","0:rip183.txt","0:rip184.txt","0:rip185.txt",
													 "0:rip186.txt","0:rip187.txt","0:rip188.txt","0:rip189.txt","0:rip190.txt",
													 "0:rip191.txt","0:rip192.txt"
	};
	
		 const char* imp[170]={"0:imp1.txt","0:imp2.txt","0:imp3.txt","0:imp4.txt","0:imp5.txt",
													 "0:imp6.txt","0:imp7.txt","0:imp8.txt","0:imp9.txt","0:imp10.txt",
													 "0:imp11.txt","0:imp12.txt","0:imp13.txt","0:imp14.txt","0:imp15.txt",
													 "0:imp16.txt","0:imp17.txt","0:imp18.txt","0:imp19.txt","0:imp20.txt",
													 "0:imp21.txt","0:imp22.txt","0:imp23.txt","0:imp24.txt","0:imp25.txt",
													 "0:imp26.txt","0:imp27.txt","0:imp28.txt","0:imp29.txt","0:imp30.txt",
													 "0:imp31.txt","0:imp32.txt","0:imp33.txt","0:imp34.txt","0:imp35.txt",
													 "0:imp36.txt","0:imp37.txt","0:imp38.txt","0:imp39.txt","0:imp40.txt",
													 "0:imp41.txt","0:imp42.txt","0:imp43.txt","0:imp44.txt","0:imp45.txt",
													 "0:imp46.txt","0:imp47.txt","0:imp48.txt","0:imp49.txt","0:imp50.txt",
													 "0:imp51.txt","0:imp52.txt","0:imp53.txt","0:imp54.txt","0:imp55.txt",
													 "0:imp56.txt","0:imp57.txt","0:imp58.txt","0:imp59.txt","0:imp60.txt",
													 "0:imp61.txt","0:imp62.txt","0:imp63.txt","0:imp64.txt","0:imp65.txt",
													 "0:imp66.txt","0:imp67.txt","0:imp68.txt","0:imp69.txt","0:imp70.txt",
													 "0:imp71.txt","0:imp72.txt","0:imp73.txt","0:imp74.txt","0:imp75.txt",
													 "0:imp76.txt","0:imp77.txt","0:imp78.txt","0:imp79.txt","0:imp80.txt",
													 "0:imp81.txt","0:imp82.txt","0:imp83.txt","0:imp84.txt","0:imp85.txt",
													 "0:imp86.txt","0:imp87.txt","0:imp88.txt","0:imp89.txt","0:imp90.txt",
													 "0:imp91.txt","0:imp92.txt","0:imp93.txt","0:imp94.txt","0:imp95.txt",
													 "0:imp96.txt","0:imp97.txt","0:imp98.txt","0:imp99.txt","0:imp100.txt",
													 "0:imp101.txt","0:imp102.txt","0:imp103.txt","0:imp104.txt","0:imp105.txt",
													 "0:imp106.txt","0:imp107.txt","0:imp108.txt","0:imp109.txt","0:imp110.txt",
													 "0:imp111.txt","0:imp112.txt","0:imp113.txt","0:imp114.txt","0:imp115.txt",
													 "0:imp116.txt","0:imp117.txt","0:imp118.txt","0:imp119.txt","0:imp120.txt",
													 "0:imp121.txt","0:imp122.txt","0:imp123.txt","0:imp124.txt","0:imp125.txt",
													 "0:imp126.txt","0:imp127.txt","0:imp128.txt","0:imp129.txt","0:imp130.txt",
													 "0:imp131.txt","0:imp132.txt","0:imp133.txt","0:imp134.txt","0:imp135.txt",
													 "0:imp136.txt","0:imp137.txt","0:imp138.txt","0:imp139.txt","0:imp140.txt",
													 "0:imp141.txt","0:imp142.txt","0:imp143.txt","0:imp144.txt","0:imp145.txt",
													 "0:imp146.txt","0:imp147.txt","0:imp148.txt","0:imp149.txt","0:imp150.txt",
													 "0:imp151.txt","0:imp152.txt","0:imp153.txt","0:imp154.txt","0:imp155.txt",
													 "0:imp156.txt","0:imp157.txt","0:imp158.txt","0:imp159.txt","0:imp160.txt",
													 "0:imp161.txt","0:imp162.txt","0:imp163.txt","0:imp164.txt","0:imp165.txt",
													 "0:imp166.txt","0:imp167.txt","0:imp168.txt","0:imp169.txt","0:imp170.txt",
	};
		 
	const char* Sin[64]={"0:sin1.txt","0:sin2.txt","0:sin3.txt","0:sin4.txt","0:sin5.txt",
													 "0:sin6.txt","0:sin7.txt","0:sin8.txt","0:sin9.txt","0:sin10.txt",
													 "0:sin11.txt","0:sin12.txt","0:sin13.txt","0:sin14.txt","0:sin15.txt",
													 "0:sin16.txt","0:sin17.txt","0:sin18.txt","0:sin19.txt","0:sin20.txt",
													 "0:sin21.txt","0:sin22.txt","0:sin23.txt","0:sin24.txt","0:sin25.txt",
													 "0:sin26.txt","0:sin27.txt","0:sin28.txt","0:sin29.txt","0:sin30.txt",
													 "0:sin31.txt","0:sin32.txt","0:sin33.txt","0:sin34.txt","0:sin35.txt",
													 "0:sin36.txt","0:sin37.txt","0:sin38.txt","0:sin39.txt","0:sin40.txt",
													 "0:sin41.txt","0:sin42.txt","0:sin43.txt","0:sin44.txt","0:sin45.txt",
													 "0:sin46.txt","0:sin47.txt","0:sin48.txt","0:sin49.txt","0:sin50.txt",
													 "0:sin51.txt","0:sin52.txt","0:sin53.txt","0:sin54.txt","0:sin55.txt",
													 "0:sin56.txt","0:sin57.txt","0:sin58.txt","0:sin59.txt","0:sin60.txt",
													 "0:sin61.txt","0:sin62.txt","0:sin63.txt","0:sin64.txt"
	};
	
	
	 const char* count[33]={"0:cou1.txt","0:cou2.txt","0:cou3.txt","0:cou4.txt","0:cou5.txt",
													 "0:cou6.txt","0:cou7.txt","0:cou8.txt","0:cou9.txt","0:cou10.txt",
													 "0:cou11.txt","0:cou12.txt","0:cou13.txt","0:cou14.txt","0:cou15.txt",
													 "0:cou16.txt","0:cou17.txt","0:cou18.txt","0:cou19.txt","0:cou20.txt",
													 "0:cou21.txt","0:cou22.txt","0:cou23.txt","0:cou24.txt","0:cou25.txt",
													 "0:cou26.txt","0:cou27.txt","0:cou28.txt","0:cou29.txt","0:cou30.txt",
													 "0:cou31.txt","0:cou32.txt","0:cou33.txt"
	};
//const unsigned short RGB_All_Light[] = {
//	 0x0002,0x0009,0x0004,
//	 0x4924,0x2492,0x9249,
//	 0x9249,0x4924,0x2492,
//	 0x0002,0x0009,0x0004,
//	 
//	 0x4924,0x2492,0x9249,
//	 0x9249,0x4924,0x2492,
//	 0x0002,0x0009,0x0004,
//	 0x4924,0x2492,0x9249,
//	 
//	 0x9249,0x4924,0x2492,
//	 0x0002,0x0009,0x0004,
//	 0x4924,0x2492,0x9249,
//	 0x9249,0x4924,0x2492
//};

//静态标志位
int NONE_flag=0;
int ALL_flag=0;
int MAGIC_flag=0;
int JJ_flag=0;
/*******************************************************************************
* Function Name  : Level_GPIO_Init(void)
* Description    : 层选管脚初始化
* Input          : None
* Output         : None
* Return         : None
* Attention		   : None
*******************************************************************************/
void Level_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType= GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
//	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_25MHz;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_10;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	//A2
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_11;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	//A0
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_12;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	//A3
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
	GPIO_Init(GPIOD,&GPIO_InitStructure);
	//A1
}

/*******************************************************************************
* Function Name  : SelectLevel(unsigned char level)
* Description    : 选层(基于译码器)
* Input          : unsigned char level
* Output         : None
* Return         : None
* Attention		   : None
*******************************************************************************/
void SelectLevel(unsigned char level)
{
	switch(level){
		case 1: {A3=0;A2=0;A1=0;A0=0;break;}
		case 2: {A3=0;A2=0;A1=0;A0=1;break;}
		case 3: {A3=0;A2=0;A1=1;A0=0;break;}
		case 4: {A3=0;A2=0;A1=1;A0=1;break;}
		case 5: {A3=0;A2=1;A1=0;A0=0;break;}
		case 6: {A3=0;A2=1;A1=0;A0=1;break;}
		case 7: {A3=0;A2=1;A1=1;A0=0;break;}
		case 8: {A3=0;A2=1;A1=1;A0=1;break;}
		case 9: {A3=1;A2=0;A1=0;A0=0;break;}
		case 10:{A3=1;A2=0;A1=0;A0=1;break;}
		case 11:{A3=1;A2=0;A1=1;A0=0;break;}
		case 12:{A3=1;A2=0;A1=1;A0=1;break;}
		default:break;
	}
	delay_us(1);
}

/*******************************************************************************
* Function Name  : FreshLevel()
* Description    : 每隔120us刷新一次层
* Input          : None
* Output         : None
* Return         : None
* Attention		   : None
*******************************************************************************/
void FreshLevel(void)
{
	SelectLevel(index_level++);
	delay_us(50);
	if(index_level == 13) index_level = 1;
}


void ShowOneTotem()
{
	int loop_index=0;
	int t=0;
	int loop_start=0;
	int i=0;
	
	SelectLevel(1);
	for(i=0;i<4;i++)																						//12层
	{
		
		for(loop_start=4752;loop_start>=3456;loop_start-=432)					
		{
			for(t=0;t<12;t++)
			{
				WriteData(0,0,0);
			}
			for(loop_index=loop_start;loop_index<(loop_start+36);loop_index++)
			{
				WriteData(Face[i][loop_index],Face[i][loop_index-1728],Face[i][loop_index-3456]);
			}
		}
		OpenLED();
//		StartLatch();
		delay_us(50);
		CloseLED();
	}

	
	SelectLevel(2);
	for(i=0;i<4;i++)																						
	{
		for(loop_start=4788;loop_start>=3492;loop_start-=432)					//11层
		{
			for(t=0;t<12;t++)
			{
				WriteData(0,0,0);
			}
			for(loop_index=loop_start;loop_index<(loop_start+36);loop_index++)
			{
				WriteData(Face[i][loop_index],Face[i][loop_index-1728],Face[i][loop_index-3456]);
			}
		}
		OpenLED();
//		StartLatch();
		delay_us(50);
		CloseLED();
	}
	
	
	SelectLevel(3);
	for(i=0;i<4;i++)																						
	{
		for(loop_start=4824;loop_start>=3528;loop_start-=432)					//10层
		{
			for(t=0;t<12;t++)
			{
				WriteData(0,0,0);
			}
			for(loop_index=loop_start;loop_index<(loop_start+36);loop_index++)
			{
				WriteData(Face[i][loop_index],Face[i][loop_index-1728],Face[i][loop_index-3456]);
			}
		}
		OpenLED();
//		StartLatch();
		delay_us(50);
		CloseLED();
	}
	
	
	SelectLevel(4);
	for(i=0;i<4;i++)																						
	{
		for(loop_start=4860;loop_start>=3564;loop_start-=432)					//9层
		{
			for(t=0;t<12;t++)
			{
				WriteData(0,0,0);
			}
			for(loop_index=loop_start;loop_index<(loop_start+36);loop_index++)
			{
				WriteData(Face[i][loop_index],Face[i][loop_index-1728],Face[i][loop_index-3456]);
			}
		}
		OpenLED();
//		StartLatch();
		delay_us(50);
		CloseLED();
	}
	
	
	
	SelectLevel(5);
	for(i=0;i<4;i++)																						
	{
		for(loop_start=4896;loop_start>=3600;loop_start-=432)					//8层
		{
			for(t=0;t<12;t++)
			{
				WriteData(0,0,0);
			}
			for(loop_index=loop_start;loop_index<(loop_start+36);loop_index++)
			{
				WriteData(Face[i][loop_index],Face[i][loop_index-1728],Face[i][loop_index-3456]);
			}
		}
		OpenLED();
//		StartLatch();
		delay_us(50);
		CloseLED();
	}

	
	
	SelectLevel(6);
	for(i=0;i<4;i++)																						
	{
		for(loop_start=4932;loop_start>=3636;loop_start-=432)					//7层
		{
			for(t=0;t<12;t++)
			{
				WriteData(0,0,0);
			}
			for(loop_index=loop_start;loop_index<(loop_start+36);loop_index++)
			{
				WriteData(Face[i][loop_index],Face[i][loop_index-1728],Face[i][loop_index-3456]);
			}
		}
		OpenLED();
//		StartLatch();
		delay_us(50);
		CloseLED();
	}

	
	SelectLevel(7);
	for(i=0;i<4;i++)																						
	{
		for(loop_start=4968;loop_start>=3672;loop_start-=432)					//6层
		{
			for(t=0;t<12;t++)
			{
				WriteData(0,0,0);
			}
			for(loop_index=loop_start;loop_index<(loop_start+36);loop_index++)
			{
				WriteData(Face[i][loop_index],Face[i][loop_index-1728],Face[i][loop_index-3456]);
			}
		}
		OpenLED();
//		StartLatch();
		delay_us(50);
		CloseLED();
	}

	
	SelectLevel(8);
	for(i=0;i<4;i++)																						
	{	
		for(loop_start=5004;loop_start>=3708;loop_start-=432)					//5层
		{
			for(t=0;t<12;t++)
			{
				WriteData(0,0,0);
			}
			for(loop_index=loop_start;loop_index<(loop_start+36);loop_index++)
			{
				WriteData(Face[i][loop_index],Face[i][loop_index-1728],Face[i][loop_index-3456]);
			}
		}
		OpenLED();
//		StartLatch();
		delay_us(50);
		CloseLED();
	}
	
	
	SelectLevel(9);
	for(i=0;i<4;i++)																						
	{
		for(loop_start=5040;loop_start>=3744;loop_start-=432)					//4层
		{
			for(t=0;t<12;t++)
			{
				WriteData(0,0,0);
			}
			for(loop_index=loop_start;loop_index<(loop_start+36);loop_index++)
			{
				WriteData(Face[i][loop_index],Face[i][loop_index-1728],Face[i][loop_index-3456]);
			}
		}
		OpenLED();
//		StartLatch();
		delay_us(50);
		CloseLED();
	}
	
	
	SelectLevel(10);
	for(i=0;i<4;i++)																						
	{
		for(loop_start=5076;loop_start>=3780;loop_start-=432)					//3层
		{
			for(t=0;t<12;t++)
			{
				WriteData(0,0,0);
			}
			for(loop_index=loop_start;loop_index<(loop_start+36);loop_index++)
			{
				WriteData(Face[i][loop_index],Face[i][loop_index-1728],Face[i][loop_index-3456]);
			}
		}
		OpenLED();
//		StartLatch();
		delay_us(50);
		CloseLED();
	}
	
	
	SelectLevel(11);
	for(i=0;i<4;i++)																						
	{
		for(loop_start=5112;loop_start>=3816;loop_start-=432)					//2层
		{
			for(t=0;t<12;t++)
			{
				WriteData(0,0,0);
			}
			for(loop_index=loop_start;loop_index<(loop_start+36);loop_index++)
			{
				WriteData(Face[i][loop_index],Face[i][loop_index-1728],Face[i][loop_index-3456]);
			}
		}
		OpenLED();
//		StartLatch();
		delay_us(50);
		CloseLED();
	}
	
	
	SelectLevel(12);
	for(i=0;i<4;i++)																						
	{
		for(loop_start=5148;loop_start>=3852;loop_start-=432)					//1层
		{
			for(t=0;t<12;t++)
			{
				WriteData(0,0,0);
			}
			for(loop_index=loop_start;loop_index<(loop_start+36);loop_index++)
			{
				WriteData(Face[i][loop_index],Face[i][loop_index-1728],Face[i][loop_index-3456]);
			}
		}
		OpenLED();
//		StartLatch();
		delay_us(50);
		CloseLED();
	}
}

/*******************************************************************************
* Function Name  : ShowALL(void)
* Description    : 灯全亮
* Input          : None
* Output         : None
* Return         : None
* Attention		   : None
*******************************************************************************/
void ShowALL(void)
{
	if(ALL_flag==0)
	{
		TFCard_Init();
		OpenFile("0:ALL.txt");
		ReadFile();
		CloseFile();
		convert();
		TFCard_Deinit();
		ALL_flag=1;
	}
	ShowOneTotem();
}

/*******************************************************************************
* Function Name  : ShowMAGIC(void)
* Description    : 魔方
* Input          : None
* Output         : None
* Return         : None
* Attention		   : None
*******************************************************************************/
void ShowMAGIC(void)
{
	if(MAGIC_flag==0)
	{
		TFCard_Init();
		OpenFile("0:MAG.txt");
		ReadFile();
		CloseFile();
		convert();
		TFCard_Deinit();
		MAGIC_flag=1;
	}
	ShowOneTotem();
}

/*******************************************************************************
* Function Name  : ShowJJ(void)
* Description    : 魔方
* Input          : None
* Output         : None
* Return         : None
* Attention		   : None
*******************************************************************************/
void ShowJJ(void)
{
	if(JJ_flag==0)
	{
		TFCard_Init();
		OpenFile("0:jj.txt");
		ReadFile();
		CloseFile();
		convert();
		TFCard_Deinit();
		JJ_flag=1;
	}
	ShowOneTotem();
}

/*******************************************************************************
* Function Name  : ShowNONE(void)
* Description    : 灯全灭
* Input          : None
* Output         : None
* Return         : None
* Attention		   : None
*******************************************************************************/
void ShowNONE(void)
{
	if(NONE_flag==0)
	{
		TFCard_Init();
		OpenFile("NONE.txt");
		ReadFile();
		CloseFile();
		convert();
		NONE_flag=1;
	}
	ShowOneTotem();
}


/*******************************************************************************
* Function Name  : ShowFPGA(void)
* Description    : 显示动画FPGA
* Input          : None
* Output         : None
* Return         : None
* Attention		   : None
*******************************************************************************/
void ShowFPGA(void)
{
		const char* boot[44]={"0:boot.txt","0:boot1.txt","0:boot2.txt","0:boot3.txt",
												"0:boot4.txt","0:boot5.txt","0:boot6.txt","0:boot7.txt",
												"0:boot8.txt","0:boot9.txt","0:boot10.txt","0:boot11.txt",
												"0:boot12.txt","0:boot13.txt","0:boot14.txt","0:boot15.txt",
												"0:boot16.txt","0:boot17.txt","0:boot18.txt","0:boot19.txt",
												"0:boot20.txt","0:boot21.txt","0:boot22.txt","0:boot23.txt",
												"0:boot24.txt","0:boot25.txt","0:boot26.txt","0:boot27.txt",
												"0:boot28.txt","0:boot29.txt","0:boot30.txt","0:boot31.txt",
												"0:boot32.txt","0:boot33.txt","0:boot34.txt","0:boot35.txt",
												"0:boot36.txt","0:boot37.txt","0:boot38.txt","0:boot39.txt",
												"0:boot40.txt","0:boot41.txt","0:boot42.txt","0:boot43.txt",
												};
	int Totem_index=0;			//动画文件下标
	speed = 7;
	for(Totem_index = 0;Totem_index<44;Totem_index++)  //44个文件
	{
		TFCard_Init();
		OpenFile(boot[Totem_index]);
		ReadFile();
		CloseFile();
		convert();
		ShowOneTotem();
		ShowOneTotem();
		ShowOneTotem();
		ShowOneTotem();
		ShowOneTotem();
		ShowOneTotem();
		ShowOneTotem();
		ShowOneTotem();
//		TFCard_Deinit();
	}
}


/*******************************************************************************
* Function Name  : ShowCUBE(void)
* Description    : 显示动画CUBE
* Input          : None
* Output         : None
* Return         : None
* Attention		   : None
*******************************************************************************/
void ShowCUBE(void)
{
	int File_index=0;
	speed = 8;
	for(File_index=0;File_index<499;File_index++)
	{
		TFCard_Init();		
		OpenFile(cube[File_index]);
		ReadFile();
		CloseFile();
		convert();
	}
}

/*******************************************************************************
* Function Name  : ShowSPIRAL(void)
* Description    : 显示动画SPIRAL
* Input          : None
* Output         : None
* Return         : None
* Attention		   : None
*******************************************************************************/
void ShowSPIRAL(void)
{
	int File_index=0;
	speed = 7;
	for(File_index=0;File_index<198;File_index++)
	{
		TFCard_Init();		
		OpenFile(spiral[File_index]);
		ReadFile();
		CloseFile();
		convert();
	}
}


/*******************************************************************************
* Function Name  : ShowSWIRLS(void)
* Description    : 显示动画SWIRLS
* Input          : None
* Output         : None
* Return         : None
* Attention		   : None
*******************************************************************************/
void ShowSWIRLS(void)
{
	int File_index=0;
	speed = 5;
	for(File_index=0;File_index<264;File_index++)
	{
		TFCard_Init();		
		OpenFile(swirls[File_index]);
		ReadFile();
		CloseFile();
		convert();
	}
}

/*******************************************************************************
* Function Name  : ShowRIPPLE(void)
* Description    : 显示动画ShowRIPPLE
* Input          : None
* Output         : None
* Return         : None
* Attention		   : None
*******************************************************************************/
void ShowRIPPLE(void)
{
	int File_index=0;
	speed = 3;
	for(File_index=0;File_index<192;File_index++)
	{
		TFCard_Init();		
		OpenFile(ripple[File_index]);
		ReadFile();
		CloseFile();
		convert();
		TFCard_Deinit();
	}
}


/*******************************************************************************
* Function Name  : ShowIMP(void)
* Description    : 显示动画ShowIMP
* Input          : None
* Output         : None
* Return         : None
* Attention		   : None
*******************************************************************************/
void ShowIMP(void)
{
	int File_index=0;
	speed = 20;
	for(File_index=0;File_index<170;File_index++)
	{
		TFCard_Init();		
		OpenFile(imp[File_index]);
		ReadFile();
		CloseFile();
		convert();
		TFCard_Deinit();
	}
}

/*******************************************************************************
* Function Name  : ShowSIN(void)
* Description    : 显示动画ShowSIN
* Input          : None
* Output         : None
* Return         : None
* Attention		   : None
*******************************************************************************/
void ShowSIN(void)
{
	int File_index=0;
	speed = 10;
	for(File_index=0;File_index<64;File_index++)
	{
		TFCard_Init();		
		OpenFile(Sin[File_index]);
		ReadFile();
		CloseFile();
		convert();
		TFCard_Deinit();
	}
}

/*******************************************************************************
* Function Name  : ShowCOUNT(void)
* Description    : 显示动画ShowCOUNT
* Input          : None
* Output         : None
* Return         : None
* Attention		   : None
*******************************************************************************/
void ShowCOUNT(void)
{
	int File_index=0;
	speed = 8;
	for(File_index=0;File_index<33;File_index++)
	{
		TFCard_Init();		
		OpenFile(count[File_index]);
		ReadFile();
		CloseFile();
		convert();
		TFCard_Deinit();
	}
		CloseLED();
		delay_ms(100);
		OpenLED();
		TFCard_Init();		
		OpenFile(count[32]);
		ReadFile();
		CloseFile();
		convert();
		TFCard_Deinit();
}


/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
