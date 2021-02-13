# ofxMouseController
==================

OpenFrameworks addon to controlling your mouse pointer on widows, linux and OSX.

## Exemples
You can find exemples in the exemple folder.

Here is a demo:
[viméo video](http://vimeo.com/103851336)

## Important

* On OSX, you must add **CoreGraphics.framework** to your Xcode project.
* On linux, with qt creator, you must add flags to your project:
```json
of.linkerFlags: of.linkerFlags: ["-lX11", "-lXtst", "-lXext"]

```

## License

The MIT License (MIT)