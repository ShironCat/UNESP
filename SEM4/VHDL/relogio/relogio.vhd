LIBRARY ieee;
USE ieee.std_logic_1164.all;

entity relogio is
	port(
		iCLK_28 : IN STD_LOGIC;
		oHEX0_D : OUT STD_LOGIC_VECTOR (6 downto 0);
		oHEX0_DP: OUT STD_LOGIC;
		oHEX1_D : OUT STD_LOGIC_VECTOR (6 downto 0);
		oHEX1_DP: OUT STD_LOGIC;
		oHEX2_D : OUT STD_LOGIC_VECTOR (6 downto 0);
		oHEX2_DP: OUT STD_LOGIC;
		oHEX3_D : OUT STD_LOGIC_VECTOR (6 downto 0);
		oHEX3_DP: OUT STD_LOGIC;
		oHEX4_D : OUT STD_LOGIC_VECTOR (6 downto 0);
		oHEX4_DP: OUT STD_LOGIC;
		oHEX5_D : OUT STD_LOGIC_VECTOR (6 downto 0);
		oHEX5_DP: OUT STD_LOGIC
	);
end relogio;

architecture relogioCircuito of relogio is
	component modularizador is
	port(
		iCLK_28 : in std_logic;
		ss: OUT STD_LOGIC
	);
	end component;
	component controlador is
	port(
		iCLK    : IN STD_LOGIC;
		oHEX2_D : OUT STD_LOGIC_VECTOR (6 downto 0);
		oHEX2_DP: OUT STD_LOGIC;
		oHEX3_D : OUT STD_LOGIC_VECTOR (6 downto 0);
		oHEX3_DP: OUT STD_LOGIC;
		oHEX4_D : OUT STD_LOGIC_VECTOR (6 downto 0);
		oHEX4_DP: OUT STD_LOGIC;
		oHEX5_D : OUT STD_LOGIC_VECTOR (6 downto 0);
		oHEX5_DP: OUT STD_LOGIC;
		oHEX6_D : OUT STD_LOGIC_VECTOR (6 downto 0);
		oHEX6_DP: OUT STD_LOGIC;
		oHEX7_D : OUT STD_LOGIC_VECTOR (6 downto 0);
		oHEX7_DP: OUT STD_LOGIC
	);
	end component;
	signal ss : std_logic;
begin
	modulacao: modularizador port map( iCLK_28, ss );
	relogio: controlador port map ( ss, oHEX0_D(6 downto 0), oHEX0_DP, oHEX1_D(6 downto 0), oHEX1_DP, oHEX2_D(6 downto 0), oHEX2_DP, oHEX3_D(6 downto 0), oHEX3_DP, oHEX4_D(6 downto 0), oHEX4_DP, oHEX5_D(6 downto 0), oHEX5_DP  );
	
end relogioCircuito;