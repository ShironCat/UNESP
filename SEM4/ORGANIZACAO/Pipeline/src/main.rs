/*
                                		Trabalho de Organização de Computadores
Luiza Torello Vieira
Victor Azadinho Miranda

1 Algoritmo a ser entregue
        Imagine um pipeline o qual você possa desprezar hazards de recursos e de dados. Você deve apenas se 
    preocupar com desvios condicionais. Escreva um programa em uma linguagem de sua preferência que leia um 
    arquivo .txt, o qual contenha um código em assembly de arquitetura 32 bits, e simule um pipeline mediante
    os comandos ali presentes. Seu programa deverá:
        1. Ler um arquivo .txt;
        2. Armazenar as instruções;
        3. Construir um pipeline a partir das instruções lidas;
        4. Mostrar para o usuáio o pipeline.
    O pipeline do seu programa deverá ter 6 est´agios:
        1. Buscar de instrução (FI);
        2. Decodificar instrução (DI);
        3. Calcular operandos (CO);
        4. Obter operandos (FO);
        5. Executar instrução (EI);
        6. Escrever operando (WO).
Entrega: 17/02/2019
*/
extern crate rand;
use rand::*;
use std::io;
use std::fs;

//Fetch instruction --> pega a próxima instrução
fn instruction_fetch(program: &Vec<Vec<String>>, program_counter: u32) -> String {
	let mut index = 1;
	let mut instruction: String = String::from("ZZZ");
	for i in program {
		if index == program_counter {
			instruction = i[0].to_string();
			break;
		} else {
			index = index + 1;
		}
	}
	instruction
}

//Decode instruction --> decodifica a instrução (define o que ela vai fazer)
fn decode_instruction(instruction: &String) -> u32 {
	let mut decoded_instruction = 0;
	if instruction.to_string() == String::from("jmp") {
		decoded_instruction = 1;
	} else if instruction.to_string() == String::from("jle") {
		decoded_instruction = 2;
	} else if instruction.to_string() == String::from("leave") {
		decoded_instruction = 3;
	} else if instruction.to_string() == String::from("ret") {
		decoded_instruction = 4;
	} else if instruction.to_string() == String::from("incl") {
		decoded_instruction = 5;
	}
	decoded_instruction
}

//Operand Calculus --> calcula o endereço do operando
fn operand_calculation(decoded_instruction: u32) -> u32 {
	let result_oc = match decoded_instruction {
		1 => 1,
		2 => 1,
		3 => 0,
		4 => 0,
		5 => 1,
		_ => 2
	};
	result_oc
}

//Fetch Operand --> pega o conteúdo do operando
fn operand_fetch( program: Vec<String>, program_counter: u32 ) {
	print!( "I{}  ", program_counter );
}

//Execute Instruction --> realiza a instrução com o operando desejado
fn execute_instruction( program: Vec<String>, jump_label: String, op_code: u32, program_counter: u32 ) -> i32 {
	if op_code == 1 { // Jump normal(A ser redefinido o número)
		let index : i32 = -1;
		for i in program {
			let index = index + 1;
			if jump_label == i {
				return index
			}
		}
	} else if op_code == 2 {//Jump condicional
		let rng = rand::thread_rng();
		print!("{:?}",rng);
		return 0
	}
	print!( "I{}  ", program_counter );
	return 0
}

//Write Operand --> grava o resultado
fn write_operand( program: Vec<String>, program_counter: u32 ) {
	//Neste caso, o WO não faz nada
	print!( "I{}  ", program_counter );
}

fn read_file(file_name: String) -> Vec<Vec<String>> {
	//Abertura do arquivo
	let content = fs::read_to_string(file_name)
		.expect("Falha na leitura do arquivo!");
	let content_lines = content.split("\n")
		.collect::<Vec<&str>>();
	let mut content_2d_vec: Vec<Vec<&str>> = Vec::new();
	let mut index = 0;
	for i in content_lines {
		content_2d_vec[index] = i.split_whitespace()
			.collect::<Vec<&str>>();
		index = index + 1;
	}
	let mut content_string: Vec<Vec<String>> = Vec::new();
	let mut index_x = 0;
	let mut index_y = 0;
	for i in content_2d_vec {
		for j in i {
			content_string[index_x][index_y] = j.to_string();
			index_y = index_y + 1;
		}
		index_x = index_x + 1;
	}
	content_string
}

fn main() {
	//Leitura do nome do arquivo
	println!("Arquivo: ");
	let mut file_name = String::new();
	io::stdin().read_line( &mut file_name )
		.expect("Falha na leitura");
	file_name.pop();//tira a quebra de linha
	let program = read_file(file_name);

	loop {
		let program_counter = 0;
		println!("     FI   DI   CO   FO   EI   WO");
		print!("{} -", program_counter );
		let mut vec_print: Vec<String> = Vec::new();
		let result_fi = instruction_fetch(&program, program_counter);
		if result_fi != String::from("ZZZ") {
			vec_print[0] = result_fi.to_string();
			let result_di = decode_instruction(&result_fi);
		} else {
			continue;
		}
		//program_counter = EI( program, jump_label, op_code, program_counter );
		//WO();
		/*if None == program[program_counter] {
			break;
		}*/
	}
}
