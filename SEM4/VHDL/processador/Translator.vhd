library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;

ENTITY Translator IS
PORT (
		
		E   : IN STD_LOGIC_VECTOR( 3 downto 0);
		S   : IN STD_LOGIC_VECTOR( 7 downto 0)
	);
END Translator;

ARCHITECTURE GOOGLE OF Translator IS
	signal x: STD_LOGIC_VECTOR(7 downto 0);
BEGIN
	process 
	begin
		case E(3 downto 0) is
				when "0000" => x <= "00000000";
				when "1000" => x <= "00000001";
				when "1001" => x <= "00000010";
				when "1010" => x <= "00000100";
				when "1011" => x <= "00001000";
				when "1100" => x <= "00010000";
				when "1101" => x <= "00100000";
				when "1110" => x <= "01000000";
				when "1111" => x <= "10000000";
		end case;
	end	process;
	S <= x;
END GOOGLE;