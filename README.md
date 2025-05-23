---

# `cpp-node-addon`

---

Este projeto é um exemplo prático de como criar e compilar um **Node.js Addon** usando **C++** e a **Node-API (N-API)**, além de automatizar a construção e a disponibilização dos binários através do **GitHub Actions**.

O objetivo principal é demonstrar um fluxo de trabalho completo, desde a escrita do código C++ e sua configuração com `node-gyp`, até a integração contínua (CI) e a entrega contínua (CD) de binários para diferentes plataformas via GitHub Releases.

## 🚀 Funcionalidades Atuais

* **Node.js Addon em C++:** Um módulo C++ simples que expõe uma função `hello()` ao JavaScript, retornando a string "world".
* **Node-API (N-API):** Utiliza a interface N-API para garantir compatibilidade binária entre diferentes versões do Node.js.
* **`node-gyp` para Compilação:** Configurado para compilar o addon C++ para Windows usando `node-gyp`.
* **GitHub Actions para CI/CD:**
    * **Automação de Build:** O workflow é acionado automaticamente na criação de novas tags (ex: `v1.0.0`).
    * **Compilação em Windows:** Constrói os binários do addon em um ambiente `windows-latest` com Node.js `v22.16.0` LTS.
    * **GitHub Releases:** Anexa os binários compilados diretamente aos GitHub Releases correspondentes à tag, facilitando o download.
* **Testes Locais Simplificados:** Inclui um script Node.js para carregar e testar o binário compilado.

## 📦 Estrutura do Projeto

```
my-node-addon-project/
├── .github/
│   └── workflows/
│       └── build-release.yml    # Workflow do GitHub Actions
├── .vscode/
│   └── c_cpp_properties.json    # Configurações do VS Code para C/C++ IntelliSense
├── src/
│   └── hello.cc                 # Código fonte C++ do Node.js Addon
├── binding.gyp                  # Arquivo de configuração do node-gyp
├── index.js                     # Script Node.js para testar o addon
├── package.json                 # Definições do projeto Node.js e scripts de compilação
└── .gitignore                   # Arquivos e diretórios a serem ignorados pelo Git
```

## 🛠️ Como Desenvolver Localmente

Para trabalhar com este projeto em sua máquina local, siga os passos abaixo:

### Pré-requisitos

* **Node.js e npm:** Instale a versão LTS do Node.js (v22.16.0 ou superior é recomendado).
* **Python 3:** Necessário para o `node-gyp`.
* **Ferramentas de Build C++ (Windows):** Instale o **Visual Studio Build Tools**. Você pode fazer isso através do Visual Studio Installer, selecionando a workload "Desenvolvimento para desktop com C++" e certificando-se de incluir as "Ferramentas de build do MSVC" e "SDK do Windows".

### Instalação e Compilação

1.  **Clone o repositório:**
    ```bash
    git clone https://github.com/AloisioMagalhaes/cpp-node-addon.git
    cd cpp-node-addon
    ```

2.  **Instale as dependências Node.js e compile o addon:**
    ```bash
    npm install
    ```
    Este comando irá instalar o `node-gyp` e, graças ao script `install` no `package.json`, também acionará a compilação do seu addon C++. O binário compilado (`hello.node`) será encontrado em `build/Release/`.

### Testando o Addon Localmente

Para verificar se o addon foi compilado corretamente e está funcionando:

```bash
node index.js
```

Você deverá ver a seguinte saída:

```
O addon nativo diz: world
Sistema operacional detectado: win32
Node.js version: v22.16.0
```

### Configuração do VS Code para C/C++ IntelliSense

Para ter autocompletar, verificação de erros e outras funcionalidades de IDE para o seu código C++, é crucial configurar o `includePath` no VS Code.

1.  Certifique-se de ter a extensão **C/C++ Extension Pack** instalada no VS Code.
2.  O arquivo `.vscode/c_cpp_properties.json` já está incluído no projeto. **Você precisará ajustar o caminho para o seu compilador `cl.exe` e a versão do Windows SDK** dentro deste arquivo para que o IntelliSense funcione corretamente em sua máquina.
    * Exemplo de `compilerPath` (ajuste o ano e a versão): `"C:/Program Files (x86)/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.29.30133/bin/Hostx64/x64/cl.exe"`
    * Exemplo de `windowsSdkVersion` (verifique o seu SDK): `"10.0.19041.0"`

## 🚀 Automação com GitHub Actions

O projeto está configurado para automatizar a construção de binários e sua disponibilização em GitHub Releases.

### Como Acionar um Build e Release

O workflow `build-release.yml` é acionado automaticamente sempre que uma **nova tag** é empurrada para o repositório, seguindo o padrão `vX.Y.Z` (ex: `v1.0.0`, `v1.0.1`).

Para criar um novo Release:

1.  Certifique-se de que todas as suas alterações estejam commitadas.
2.  Crie uma nova tag localmente:
    ```bash
    git tag v1.0.0 # Use a próxima versão relevante (ex: v1.0.1, v1.0.2)
    ```
3.  Empurre a tag para o GitHub:
    ```bash
    git push origin v1.0.0
    ```

### Monitorando o Workflow

Após empurrar a tag, vá para a aba **"Actions"** no seu repositório GitHub (`https://github.com/AloisioMagalhaes/cpp-node-addon/actions`). Você verá o workflow `Build C++ Node Addon and Release for Windows` em execução.

### Baixando Binários do GitHub Releases

Uma vez que o workflow for concluído com sucesso, os binários compilados estarão disponíveis na aba **"Releases"** do seu repositório GitHub (`https://github.com/AloisioMagalhaes/cpp-node-addon/releases`).

Você poderá baixar o arquivo `node-addon-windows-x64-v22.16.0.zip` (ou similar) e descompactá-lo para obter o `hello.node` pronto para uso.

## 🤝 Contribuição

Sinta-se à vontade para explorar, modificar e adaptar este projeto para suas próprias necessidades. Se tiver sugestões ou encontrar problemas, por favor, abra uma `Issue`.

---
