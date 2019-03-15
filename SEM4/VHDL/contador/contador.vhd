LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY contador IS	
	PORT(
		iSW :   IN STD_LOGIC_VECTOR (1 downto 0);
		iKEY :   IN STD_LOGIC_VECTOR (0 downto 0);
		oHEX0_D : OUT STD_LOGIC_VECTOR (6 downto 0);
		oHEX0_DP : OUT STD_LOGIC
	);
END contador;

ARCHITECTURE hardwareContador OF contador IS 

	COMPONENT FlipFlopT IS
		PORT(   iSW:   IN STD_LOGIC;
				iSW1:   IN STD_LOGIC;
				iKEY:   IN STD_LOGIC;
				oLEDR : OUT STD_LOGIC
		);
	END COMPONENT;	
	
	COMPONENT BinToHex4 IS
		PORT (
			iSW : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
			oHEX0_D : OUT STD_LOGIC_VECTOR(6 DOWNTO 0);
			oHEX0_DP : OUT STD_LOGIC
		);
	END COMPONENT;
	
	SIGNAL s : STD_LOGIC_VECTOR(3 downto 0);
	SIGNAL e : STD_LOGIC_VECTOR(3 DOWNTO 0);
	
	BEGIN
	
	cont1 : FlipFlopT port map(iSW(0),not iSW(1), iKEY(0), s(0));
	e(0) <= iSW(0) AND s(0);
	cont2 : FlipFlopT port map(e(0),not iSW(1), iKEY(0), s(1));
	e(1) <= e(0) AND s(1);
	cont3 : FlipFlopT port map(e(1),not iSW(1), iKEY(0), s(2));
	e(2) <= e(1) AND s(2);
	cont4 : FlipFlopT port map(e(2),not iSW(1), iKEY(0), s(3));
	
	hex : BinToHex4 port map(s(3 downto 0),oHEX0_D(6 downto 0),oHEX0_DP);  
	
	END hardwareContador;
	