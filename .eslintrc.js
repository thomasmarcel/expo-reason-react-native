module.exports = {
    "env": {
        "browser": true,
        "es6": true,
        "node": true,
        "jest": true,
        "react-native/react-native": true
    },
    "extends": [
        "eslint:recommended",
        "plugin:react-native-a11y/recommended",
        // "plugin:react-native/recommended",
        "plugin:react/recommended",
    ],
    "globals": {
        "Atomics": "readonly",
        "SharedArrayBuffer": "readonly"
    },
    // "parser": "babel-eslint",
    "parserOptions": {
        "ecmaFeatures": {
            "jsx": true
        },
        "ecmaVersion": 2018,
        "sourceType": "module"
    },
    "plugins": [
        "react",
        "react-native",
        "react-native-a11y"
    ],
    "rules": {
        "react-native/no-unused-styles": 2,
        "react-native/split-platform-components": 2,
        "react-native/no-inline-styles": 1,
        "react-native/no-color-literals": 2,
        "react-native/no-raw-text": 2,
        "react-native/sort-styles": 1,
        "prefer-arrow-callback": 1,
    }
};
