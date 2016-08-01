{
  "targets": [
    {
      "target_name": "addon",
      "sources": [ "src/addon.cpp", "src/aibot.cpp", "src/time.cpp"],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}