{
  "targets": [
    {
      "target_name": "hello",
      "sources": [ "src/hello.cc" ],
      "defines": [
        "NAPI_DISABLE_CPP_EXCEPTIONS"
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ]
    }
  ]
}