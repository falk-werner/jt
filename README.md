[![Build](https://github.com/falk-werner/jt/actions/workflows/build.yaml/badge.svg)](https://github.com/falk-werner/jt/actions/workflows/build.yaml)

# jt

Template engine working with json data.

## Usage

### Command Line

hobbies.jt.txt:
```
{{loop hobbies}}{{ .whom }} likes {{ name }}.
{{end}}
```

hobbies.json:
```json
{
    "whom": "Bob",
    "hobbies": [
        {"name": "music"},
        {"name": "sports"},
        {"name": "food"}
    ]
}
```

Render template on command line:
```bash
jt -t hobbies.js.txt -d hobbies.json
```

Result:
```
Bob likes music.
Bob likes sports.
Bob likes food.
```

### C++

```C++
#include <jt/jt.hpp>

//...

std::string const templ = "Hello, {{whom}}!";
auto data = json::parse(R"({"whom":"world"})");

auto result = jt::render(templ, data);
// Hello, world!
```

## Templates

```
Variable: {{ variable }}
Loop: {{loop group}} ... {{end}}
Escape: {{ {{ }}
```

### Path


Paths are used to reference elements in the json data.
A path is a collection of path elements separated by a dot (`.`).
There are relative and absolute path.

A relative path refences an element relative to the current context.
An absolute path references an element relative to the root.

#### Examples

```
some.relative.path
.an.absolute.path
```

### Variable

```
Variable: {{ path }}
```

#### Example

Template:
```
"Hello, {{whom}}!"
```

JSON data:
```json
{"whom": "world"}
```

Result:
```
Hello, world!
```

### Loop

```
{{loop path}}
...
{{end}}
```

#### Example

Template:
```
Recipe: {{ title }}
Ingredients:
{{loop ingredients}}- {{ name }}{{end}}
```

JSON data:
```
{
    "title": "Fruit Salad",
    "ingredients": [
        {"name": "pineapple"},
        {"name": "kiwi"},
        {"name": "grapes"},
        {"name": "strawberries"},
        {"name": "blueberries"}
    ]
}
```

Result:
```
Recipe: Fruit Salad
Ingredients:
- pineapple
- kiwi
- grapes
- strawberries
- blueberries
```

### Escape

```
{{ {{ }}
```

## CLI

```bash
jt -t TEMPLATE -d DATA
```

| Argument | Type | Description |
| -------- | ---- | ----------- |
| TEMPLATE | path | Path of the template file. |
| DATA     | path | Path of the data file (json). |


## Dependencies

- [nlohmann/json](https://github.com/nlohmann/json)

### Development Dependencies

- [GoogleTest](https://github.com/google/googletest)