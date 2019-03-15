LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY aula01 IS
PORT (
	iSW : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
	oHEX0_D : OUT STD_LOGIC_VECTOR(6 DOWNTO 0);
	oHEX0_DP : OUT STD_LOGIC
);
END aula01;

ARCHITECTURE aula01Comportamento OF aula01 IS
BEGIN
	oHEX0_D <= NOT iSW(6 DOWNTO 0);
	oHEX0_DP <= NOT iSW(7);

END aula01Comportamento;