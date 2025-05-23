# Node.js Addon em C++: Exemplo Básico

Este repositório demonstra um exemplo simples de como criar e utilizar um **Node.js Addon** desenvolvido em **C++**. Addons são módulos que permitem estender as funcionalidades do Node.js utilizando linguagens compiladas como C ou C++, o que é ideal para operações que exigem alta performance ou acesso a bibliotecas nativas.

---

## 🚀 Começando

Para começar a explorar e testar este Node.js Addon, siga os passos abaixo. Certifique-se de ter o **Node.js** e o **npm** (Node Package Manager) instalados em sua máquina.

### Pré-requisitos

Antes de tudo, você precisará das seguintes ferramentas:

* **Node.js**: [Download oficial](https://nodejs.org/en/download/)
* **npm**: Geralmente vem junto com o Node.js.
* **Compilador C++**:
    * No Windows: [Visual Studio com C++ Desktop Development](https://visualstudio.microsoft.com/vs/community/)
    * No macOS: [Xcode Command Line Tools](https://developer.apple.com/xcode/features/) (`xcode-select --install`)
    * No Linux: [build-essential](https://packages.ubuntu.com/search?keywords=build-essential) (`sudo apt-get install build-essential` ou equivalente)

### Instalação

1.  **Clone o repositório:**
    ```bash
    git clone [https://github.com/AloisioMagalhaes/cpp-node-addon.git](https://github.com/AloisioMagalhaes/cpp-node-addon.git)
    cd cpp-node-addon
    ```

2.  **Instale as dependências e compile o Addon:**
    ```bash
    npm install
    ```
    Este comando não apenas instala as dependências do Node.js, mas também executa o script de compilação do Addon C++ (definido no `package.json` usando `node-gyp`).

---

## 📦 Estrutura do Projeto

O projeto é organizado da seguinte forma:

* `src/`: Contém os arquivos-fonte C++ do Addon.
    * `addon.cc`: O arquivo principal do Addon, onde as funções C++ são expostas ao JavaScript.
* `binding.gyp`: Arquivo de configuração para o `node-gyp`, que define como o Addon C++ deve ser compilado.
* `index.js`: Um exemplo de como importar e utilizar o Node.js Addon em um script JavaScript.
* `package.json`: Metadados do projeto e scripts para compilação.
* `.github/workflows/`: Contém os arquivos de configuração do GitHub Actions.

---

## 💡 Como Funciona

Este exemplo simples exporta uma função C++ para o ambiente Node.js. O fluxo geral é:

1.  O arquivo **`addon.cc`** em C++ define uma função (por exemplo, `MyFunction`) e a "registra" para ser acessível via Node.js.
2.  O **`binding.gyp`** instrui o `node-gyp` sobre como compilar o código C++ em um arquivo `.node` (o módulo nativo).
3.  No **`index.js`**, usamos `require('./build/Release/addon.node')` (ou `Debug`, dependendo do ambiente) para carregar o módulo nativo.
4.  As funções expostas do C++ podem então ser chamadas diretamente do JavaScript como métodos do módulo carregado.

---

## ⚙️ Uso

Após a instalação, você pode executar o exemplo para ver o Addon em ação:

```bash
node index.js
````

Você deverá ver a saída da função C++ sendo exibida no console\!

-----

## 🚀 Automação com GitHub Actions

Este repositório utiliza **GitHub Actions** para automatizar o processo de build e teste do Node.js Addon. Isso garante que o código compile corretamente e funcione como esperado sempre que houver uma alteração.

### Como Funciona

O fluxo de trabalho está configurado no arquivo `.github/workflows/main.yml` (ou um nome similar, dependendo da sua configuração). Ele é acionado em eventos específicos (por exemplo, `push` para o branch `main` ou `pull_request`).

Basicamente, o workflow executa os seguintes passos:

1.  **Define o ambiente:** Especifica o sistema operacional (Ubuntu, macOS, Windows) e a versão do Node.js a ser usada.
2.  **Verifica o código:** Clona o seu repositório.
3.  **Configura o Node.js:** Instala a versão do Node.js definida.
4.  **Instala as dependências:** Executa `npm install`, que também é responsável por compilar o Addon C++ usando `node-gyp`.
5.  **Executa testes (se houver):** Se você tiver scripts de teste definidos no `package.json`, eles seriam executados aqui para verificar a funcionalidade do Addon. (Atualmente, este projeto não inclui testes explícitos, mas é um passo importante para um projeto real).

### Benefícios do GitHub Actions

  * **Integração Contínua (CI):** Garante que o código sempre compile e quebre menos.
  * **Feedback Rápido:** Você sabe rapidamente se uma alteração quebrou a build ou a funcionalidade.
  * **Padronização do Ambiente:** A build sempre ocorre em um ambiente limpo e consistente, evitando problemas de "funciona na minha máquina".

-----

## Contribuições

Sinta-se à vontade para abrir issues, enviar pull requests ou sugerir melhorias. Toda contribuição é bem-vinda\!

-----

## Licença

Este projeto está licenciado sob a Licença MIT. Veja o arquivo [LICENSE](https://www.google.com/search?q=LICENSE) para mais detalhes.

-----

## Contato

[Aloisio Magalhães](https://www.google.com/search?q=https://github.com/AloisioMagalhaes)

```
