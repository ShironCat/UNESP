library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;

entity ULA4BITS is
	port(
		A, B : in std_logic_vector(7 downto 0);
		o    : out std_logic_vector(7 downto 0);
		sel  : in std_logic_vector(1 downto 0)
	);
end ULA4BITS;

architecture ULA4BITS_ARQ of ULA4BITS is
begin
	process(A, B, sel)
	begin
		case sel is
			when "10" => o <= A + B;
			when "11" => o <= A - B;
			when others => o <= "ZZZZ";
		end case;
	end process;
end ULA4BITS_ARQ;