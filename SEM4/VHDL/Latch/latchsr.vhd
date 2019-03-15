LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY latchsr IS
PORT(
	iSW : IN STD_LOGIC_VECTOR(1 downto 0);
	oLEDR : OUT STD_LOGIC_VECTOR(1 downto 0)
);
END latchsr;

ARCHITECTURE latchsrbehaviour OF latchsr IS
SIGNAL SS: STD_LOGIC;
SIGNAL S : STD_LOGIC;
SIGNAL SR: STD_LOGIC;
SIGNAL R : STD_LOGIC;
BEGIN
	
	S  <= iSW(0);
	R  <= iSW(1);
	SS <= S NAND SR;
	SR <= R NAND SS;
	
	oLEDR(0) <= SS;
	oLEDR(1) <= SR;

END latchsrbehaviour;