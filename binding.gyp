{
  "targets": [
    {
      "target_name": "nativeusersettings",
      "cflags": [
        "-fno-exceptions",
        "-std=c++17"
      ],
      "cflags!": [
        "-fno-exceptions",
        "-std=c++17"
      ],
      "cflags_cc!": [
        "-fno-exceptions",
        "-std=c++17"
      ],
      "cflags_cc": [
        "-fno-exceptions",
        "-std=c++17"
      ],
      "sources": [ "nativeusersettings.cc" ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}
