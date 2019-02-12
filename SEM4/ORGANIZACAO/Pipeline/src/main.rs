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
		_ => 2
	};
	result_oc
}

//Fetch Operand --> pega o conteúdo do operando
fn operand_fetch( program: &Vec<Vec<String>>, operand_number: u32, program_counter: u32) -> Vec<String> {
	let mut operands: Vec<String> = Vec::new();
	match operand_number {
		2 => {	operands[0] = program[program_counter as usize][1].to_string();
				operands[1] = program[program_counter as usize][2].to_string()
			}
		1 =>	operands[0] = program[program_counter as usize][1].to_string(),
		0 => 	operands[0] = "".to_string(),
		_ => 	panic!()
	}
	operands
}

fn jump ( program: &Vec<Vec<String>>, jump_label: Vec<String> ) -> u32 {
	let mut index : u32 = 0;
	//Varre as linhas do programa
	for i in program {
		let aux = i[0].to_string();
		aux.pop();
		index = index + 1;
		//Quando a label para a qual se deve pular for igual a label do programa
		if jump_label[0].to_string() == aux.to_string() {
		//Retorna a diferença ( novo número da linha )
			return index;
		}
	}
	return index;
}

//Execute Instruction --> realiza a instrução com o operando desejado
fn execute_instruction( program: &Vec<Vec<String>>, jump_label: Vec<String>, op_code: u32, program_counter: u32 ) -> u32 {
	if op_code == 1 { // Jump normal
		return jump( &program, jump_label );
	} else if op_code == 2 {//Jump condicional
		let rng = rand::thread_rng();
		//Condição do pulo é válida -> pula linha
		if rng {
			return jump( &program, jump_label );
		}
	}
	return program_counter + 1
}

//Write Operand --> grava o resultado
fn write_operand( program: &Vec<Vec<String>>, program_counter: u32 ) {
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
	let index = 0;
	for i in content_lines {
		content_2d_vec[index] = i.split_whitespace()
			.collect::<Vec<&str>>();
	panic!("cu");
		let index = index + 1;
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
	let mut program_counter = 0;
	let mut buffer: Vec<String> = Vec::new();
	let mut index = 0;
	while index < 6 {
		buffer.push(String::from("-1"));
		index = index + 1;
	}
	println!("     FI   DI   CO   FO   EI   WO");
	loop {
		print!("{} -", program_counter );
		let mut vec_print: Vec<String> = Vec::new();
		let result_fi = instruction_fetch(&program, program_counter);
		if result_fi != String::from("ZZZ") {
			vec_print[0]  = result_fi.to_string();
			let op_code = decode_instruction(&result_fi);
			let operand_number = operand_calculation( op_code );
			let operands  = operand_fetch( &program, operand_number, program_counter );
			program_counter = execute_instruction( &program, operands, op_code, program_counter );
			write_operand( &program, program_counter );
		} else {
			continue;
		}
	}
}
