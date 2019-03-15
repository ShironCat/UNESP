LIBRARY ieee;
USE ieee.std_logic_1164.all;

entity processador is
	iKEY : IN STD_LOGIC_VECTOR(0 downto 0);
	iSW  : IN STD_LOGIC_VECTOR(7 downto 0);
	
end processador;

architecture processo of processador is
	component uc is
	port(
		clk   : in  std_logic;
		estado: in  std_logic;
		ir    : in  std_logic_vector(7 downto 0);
		reg	  : out std_logic_vector(3 downto 0);
		mux	  : out std_logic_vector(3 downto 0);
		ula   : out std_logic_vector(2 downto 0);
		a	  : out std_logic;
		ready : out std_logic
	);
	end component;
	component Multiplexador is
	PORT (
		Y1: IN STD_LOGIC;
		Y2: IN STD_LOGIC;
		iKEY : IN STD_LOGIC_VECTOR;
		Saida: OUT STD_LOGIC
	);
	END COMPONENT;
	COMPONENT registrador IS
	PORT ( 
		iSW : IN STD_LOGIC_VECTOR(3 downto 0);
		iSW1: IN STD_LOGIC;
		iKEY: IN STD_LOGIC_VECTOR(0 downto 0);
		oSW : OUT STD_LOGIC_VECTOR(3 downto 0)
	);
	END COMPONENT;
	COMPONENT ula IS
	PORT (
		A, B : in std_logic_vector(3 downto 0);
		o    : out std_logic_vector(3 downto 0);
		sel  : in std_logic_vector(1 downto 0)
	);
	END COMPONENT;
BEGIN

END processo;