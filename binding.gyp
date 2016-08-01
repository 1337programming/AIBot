{
  "targets": [
    {
      "target_name": "addon",
      "sources": [ "src/addon.cpp", "src/aibot.cpp"],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}