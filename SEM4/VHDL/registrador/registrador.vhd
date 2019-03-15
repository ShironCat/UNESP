LIBRARY ieee;
USE ieee.std_logic_1164.all;
ENTITY registrador IS 
	PORT ( 
		iSW : IN STD_LOGIC_VECTOR(7 downto 0);
		iSW1: IN STD_LOGIC;
		iKEY: IN STD_LOGIC_VECTOR(0 downto 0);
		oSW : OUT STD_LOGIC_VECTOR(7 downto 0)
	);
END registrador;
ARCHITECTURE registradorBehaviour OF registrador IS 
	COMPONENT flipflop IS 
		PORT ( 
			I : IN STD_LOGIC;
			clk: IN STD_LOGIC;
			enable : IN STD_LOGIC;
			O : OUT STD_LOGIC
		);
	END COMPONENT;
BEGIN
	bit0 : flipflop port map( iSW(0), iKEY(0), iSW1, oSW(0) );
	bit1 : flipflop port map( iSW(1), iKEY(0), iSW1, oSW(1) );
	bit2 : flipflop port map( iSW(2), iKEY(0), iSW1, oSW(2) );
	bit3 : flipflop port map( iSW(3), iKEY(0), iSW1, oSW(3) );
	bit4 : flipflop port map( iSW(4), iKEY(0), iSW1, oSW(4) );
	bit5 : flipflop port map( iSW(5), iKEY(0), iSW1, oSW(5) );
	bit6 : flipflop port map( iSW(6), iKEY(0), iSW1, oSW(6) );
	bit7 : flipflop port map( iSW(7), iKEY(0), iSW1, oSW(7) );

END registradorBehaviour;