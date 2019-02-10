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
use std::io;
use std::fs;

//Fetch instruction --> pega a próxima instrução
fn FI(program: Vec<String>, program_counter: u32) -> String {
	let mut index = 1;
	let instruction: String = String::from("ZZZ");
	for i in program {
		if index == program_counter {
			let instruction = i;
			break;
		} else {
			index = index + 1;
		}
	}
	instruction
}

//Decode instruction --> decodifica a instrução (define o que ela vai fazer)
fn DI() {
	//Definir todos os comandos do assembly em um arquivo separado
	let commandList : [String, 11] = ["pushl", "movl", "subl","cmpl","jne","jmp","decl","call","imull","leave","ret"];
	print!(" DI -->");
}

//Operand Calculus --> calcula o endereço do operando
fn CO() {
	print(" CO -->");
}

//Fetch Operand --> pega o conteúdo do operando
fn FO() {
	print!(" FO -->");
}

//Execute Instruction --> realiza a instrução com o operando desejado
fn EI() {
	print!(" EI --");
}

//Write Operand --> grava o resultado
fn WO() {
	print!(" WO ");
}

fn ReadFile<'a>(file_name: String) -> Vec<&'a str> {
	//Abertura do arquivo
	let content = fs::read_to_string(file_name).expect("Falha na leitura do arquivo!");
	let content = content.split_whitespace()
		.collect::<Vec<_>>();
	content
}

fn Main() {
	let mut program_counter = 1;
	//Leitura do nome do arquivo
	println!("Arquivo: ");
	let file_name = String::new();
	io::stdin().read_line( &mut file_name )
		.expect("Falha na leitura");
	file_name.pop();
	let program = ReadFile(file_name);

	/* //.split_whitespace() divide a string em várias, separando-as pelos espaços em branco
	let mut contents = contents.split_whitespace();
	let instruction = contents.next();

	//Enquanto o próximo pedaço da String for diferente de nulo
	while { assert_ne!( None, instruction ) } {
		print!("\nInstrução ")
		FI( instruction );

		//Leitura da próxima instrução
		let mut instruction = contents.next();
	} */
}
