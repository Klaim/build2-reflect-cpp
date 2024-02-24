# reflect-cpp - A C++ library

The `reflect-cpp` C++ library provides <SUMMARY-OF-FUNCTIONALITY>.


## Usage

To start using this library in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: reflect-cpp ^<VERSION>
```

Then import the library in your `buildfile`:

```
import libs = reflect-cpp%lib{<TARGET>}
```


## Importable targets

This package provides the following importable targets:

```
lib{<TARGET>}
```

<DESCRIPTION-OF-IMPORTABLE-TARGETS>


## Configuration variables

This package provides the following configuration variables:

```
[bool] config.reflect_cpp.<VARIABLE> ?= false
```

<DESCRIPTION-OF-CONFIG-VARIABLES>
