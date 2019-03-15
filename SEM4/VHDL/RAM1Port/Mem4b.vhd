LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY Mem4b IS
	PORT
	(
		iSW		: IN STD_LOGIC_VECTOR (8 DOWNTO 0);
		iKEY	: IN STD_LOGIC_VECTOR (0 DOWNTO 0);
		oHEX0_D  : OUT STD_LOGIC_VECTOR(6 DOWNTO 0);
		oHEX0_DP : OUT STD_LOGIC;
		oHEX1_D  : OUT STD_LOGIC_VECTOR(6 DOWNTO 0);
		oHEX1_DP : OUT STD_LOGIC;
		oHEX2_D  : OUT STD_LOGIC_VECTOR(6 DOWNTO 0);
		oHEX2_DP : OUT STD_LOGIC
	);
END Mem4b;

ARCHITECTURE Mem4b_Behaviour OF Mem4b IS

COMPONENT RAM1Port IS
	PORT
	(
		address		: IN STD_LOGIC_VECTOR (3 DOWNTO 0);
		clock		: IN STD_LOGIC;
		data		: IN STD_LOGIC_VECTOR (3 DOWNTO 0);
		wren		: IN STD_LOGIC ;
		q		: OUT STD_LOGIC_VECTOR (3 DOWNTO 0)
	);
END COMPONENT;

COMPONENT BinToHex4 IS
PORT (
	iSW      : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
	oHEX0_D  : OUT STD_LOGIC_VECTOR(6 DOWNTO 0);
	oHEX0_DP : OUT STD_LOGIC
);
END COMPONENT;
	SIGNAL saida: STD_LOGIC_VECTOR(3 DOWNTO 0);
BEGIN

	--Endereço
	bin1: BinToHex4 port map(iSW(3 DOWNTO 0), oHEX0_D(6 DOWNTO 0), oHEX0_DP);
	--Dados de entrada
	bin2: BinToHex4 port map(iSW(7 DOWNTO 4), oHEX1_D(6 DOWNTO 0), oHEX1_DP);
	--Dados de saída
	bin3: BinToHex4 port map(saida(3 DOWNTO 0), oHEX2_D(6 DOWNTO 0), oHEX2_DP);
	RAM: RAM1Port port map (iSW(3 DOWNTO 0), iKEY(0), iSW(7 DOWNTO 4), iSW(8), saida(3 downto 0));

END Mem4b_Behaviour;