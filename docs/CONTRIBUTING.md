<!-- --------------------------------------------------- -->
<!-- Only used if you use markdownlint VS Code extension -->

<!-- markdownlint-disable no-inline-html -->
<!-- --------------------------------------------------- -->

<h1 align="center">
    CONTRIBUTING.md
</h1>

> [Return to README.md](../README.md)

Thank you for deciding to read this document

Why did I decide this? This is an educational, non-commercial project, and the kernel itself will never be finished - so I don't intend to accept any financial or other assistance. Thank you for your understanding.

However, for those who will be working on this project with me, the rules that must be followed are outlined below.

## 1. Git branches

1. All branches must have a prefix:

    - `dev/` - A branch for working on the code. Anything goes—adding new features, refactoring, fixing bugs—it’s all in this branch. A successful pull request from here triggers both GitHub Actions.
    - `docs/` - A branch for updating documentation. If a pull request to the main branch is successful, it will not trigger GitHub Actions. `.gitignore`, `.gitattributes` and `shell.nix` and other such files are also updated in this category.
    - `web/` - A branch for updating the project's website, where you can test the kernel. A successful pull request to the main branch from this branch triggers a GitHub Action designed to update the website.
    - `ci/` - A branch for changes in GitHub Actions. When successfully merged into the main branch, it triggers all GitHub Actions.

2. The branch name should include a brief description of what is being done in it. For example, `dev/refactoring`.

3. `the-wired` - main branch, and the `!dev/artificial-suicide` - dev branch.

    > Note:
    > `!dev` prefix to ensure that the branch is always second on the list of branches on GitHub and stands out from the other `dev` branches. You can ignore the name.

4. `the-wired` should always contain only stable versions, `!dev/artificial-suicide` contains the latest code.

5. No direct commits to `the-wired` or `!dev/artificial-suicide`. Only pull requests from other branches to `!dev/artificial-suicide`, and later, once a stable version is reached, a pull request from `!dev/artificial-suicide` to `the-wired`.

## 2. Git commits

1) All commits must begin with an appropriate emoji from [this site](https://gitmoji.dev/). This serves no specific purpose, but it provides a slightly better understanding of what the commit does and makes the commit history more visually appealing.

2) A commit should include brief, concise information about what it adds. Commits that are too long are more of a hindrance than a help.

3) It is prohibited to generate commit titles using AI.

4) If you're updating documentation or files like `.gitignore`, `.girattributes`, or `.editorconfig`, you don't have to specify in the commit message exactly what you changed there. It's enough to update that file in a separate commit from the others and write, for example, `📝 .gitignore update`, where `.gitignore` is replaced with the name of the file you changed.

## 3. Code rules

1) The use of AI is permitted to create a quick prototype of a particular feature - for example, to try to figure out how something works - but its final version must always be written manually by a programmer.

2) If file used only for X64 arch, you need to put `#if defined(X64)` on the start of the file, and `#endif` in the end. Previously, I specified source files manually, now they are searched for automatically - it's impossible to specify which ones should be compiled and which ones shouldn't, so the easiest way to avoid problems is to use preprocessor directives.

3) Only global header files that can be used anywhere in the kernel code are placed in the root of the `src/include` directory. However, if certain definitions are to be used only within a specific module or driver, the `.h` file with the corresponding name must be located in the `src/include/private` directory.

4) For now, there won't be many code-related rules, since I'm the only developer at the moment, and I'm not really sure what specific rules I want to see here

## 4. Files

1) I don't think I need to explain what should be in directories such as `src`, `makefiles`, `docs`, `.github`, and `web`.

2) Project's root folder used only for `README.md`, `.editorconfig`, `LICENSE` and `git` settings and other folders.

3) As obvious as it may seem, scripts that are not related to the kernel build must be placed in the `scripts` directory. If a script requires certain files - and if those files are not used elsewhere in the project and are needed only by that script - they must be placed in `scripts/assets`.
