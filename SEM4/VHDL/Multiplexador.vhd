LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY Multiplexador IS
PORT (
		
		ED   : IN STD_LOGIC_VECTOR( 7 downto 0);
		ER0  : IN STD_LOGIC_VECTOR( 7 downto 0);
		ER1  : IN STD_LOGIC_VECTOR( 7 downto 0);
		ER2  : IN STD_LOGIC_VECTOR( 7 downto 0);
		ER3  : IN STD_LOGIC_VECTOR( 7 downto 0);
		ER4  : IN STD_LOGIC_VECTOR( 7 downto 0);
		ER5  : IN STD_LOGIC_VECTOR( 7 downto 0);
		ER6  : IN STD_LOGIC_VECTOR( 7 downto 0);
		ER7  : IN STD_LOGIC_VECTOR( 7 downto 0);
		EG   : IN STD_LOGIC_VECTOR( 7 downto 0);
		SEL  : IN STD_LOGIC_VECTOR(3 downto 0);
		clk: IN STD_LOGIC_VECTOR(0 downto 0);
		Saida: OUT STD_LOGIC_VECTOR( 7 downto 0)
);
END Multiplexador;

ARCHITECTURE Mux OF Multiplexador IS
	signal x: STD_LOGIC_VECTOR(7 downto 0);
BEGIN
	process ( clk )
	begin
		if clk'event then
			case SEL(3 downto 0) is
				when "0000" => x <= ER0;
				when "0001" => x <= ER1;
				when "0010" => x <= ER2;
				when "0011" => x <= ER3;
				when "0100" => x <= ER4;
				when "0101" => x <= ER5;
				when "0110" => x <= ER6;
				when "0111" => x <= ER7;
				when "1000" => x <= EG;
				when "1001" => x <= ED;
			end case;
		end if;
	end	process;
	Saida <= x;
END Mux;