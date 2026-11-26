use std::io;
fn main() {
    println!("===== MINI ALU RISC-V =====\n");
    println!("Digite o primeiro valor:");
    let mut first_value = String::new();

    io::stdin()
        .read_line(&mut first_value)
        .expect("Falha ao ler a linha");

    println!("Digite o segundo valor:");
    let mut second_value = String::new();

    io::stdin()
        .read_line(&mut second_value)
        .expect("Falha ao ler a linha");

    let first_value: u32 = match first_value.trim().parse() {
        Ok(num) => num,
        Err(notnum) => {
            let notnum: String = notnum.to_string();
            println!("{notnum}");
            0
        }
    };

    let second_value: u32 = match second_value.trim().parse() {
        Ok(num) => num,
        Err(notnum) => {
            let notnum: String = notnum.to_string();
            println!("{notnum}");
            0
        }
    };
    println!("1 - ADD (Adição)\n2 - SUB (Subtração)");
    let mut signal = String::new();

    loop {
        io::stdin()
            .read_line(&mut signal)
            .expect("Falha ao ler a linha");
        if signal.trim() == "2" {
            println!(
                "{first_value} - {second_value} = {}",
                first_value - second_value
            );
            break;
        }
        if signal.trim() == "1" {
            println!(
                "{first_value} + {second_value} = {}",
                first_value + second_value
            );
            break;
        }
        println!("Por favor digite um valor correto!!");
        continue;
    }
}
