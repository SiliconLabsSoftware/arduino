# Contributing guidelines and rules

Thank you for your interest in contributing to this free and open source project! We welcome all community contributions.

To keep things clean and maintainable, we have a few rules:

## Pull requests
1. New features and larger refactors need to be discussed first
    - 1.1 Look through the existing issues first to see if one has already been submitted for the change
    - 1.2 All new features must have an issue where discussions can be facilitated
2. Pull request title and description should follow the same guidelines as commit messages
3. Pull requests shall target the "main" branch by default
4. Default workflow for contributions is: `fork -> branch -> commit -> push -> PR -> review -> CI -> rebase (if needed) -> merge`
5. Rebasing pull requests is encouraged. After submitting your pull request some changes may be requested. Rather than adding unnecessary extra commits to the pull request, you can squash these changes into the existing commit and then do a force push to your fork. When you force push to your fork, the PR is automatically updated with your new changes, so there is no need to open a new PR. Leave a comment on the pull request thread to explain that the history has been changed. This will help to keep the commit history of the repository clean.
6. No merge commits - only linear history is allowed - always rebase instead of merging the upstream. Use `git pull --rebase` or `git fetch upstream && git rebase upstream/main`.
7. Commits should be atomic. This means that a commit completely accomplishes a single task. Each commit should result in fully functional code. Multiple tasks should not be combined in a single commit, but a single task should not be split over multiple commits. For more information see [http://www.freshconsulting.com/atomic-commits](http://www.freshconsulting.com/atomic-commits)
8. Each pull request should address a single bug fix or enhancement. This may consist of multiple commits. If you have multiple, unrelated fixes or enhancements to contribute, submit them as separate pull requests.
9. If your pull request fixes an issue in the issue tracker, use the [closes/fixes/resolves syntax](https://help.github.com/articles/closing-issues-via-commit-messages) in the body to indicate this
10. All pull requests must go through a code review and must be approved by the project administrators before merging
    - 10.1 When your code is critiqued, questioned, or constructively criticized, remember that you are not your code. Do not take the code review personally.
11. CI (GH actions) must pass before merging
12. Any code producing compiler warnings is not accepted
13. When applicable, test your code on hardware and make sure your changes work in real life and not just in theory
14. New examples must be added to the build tests under `tests/build/`
15. Pull requests with over one month of inactivity are subject to be closed

### Commit messages
1. Use the [imperative mood](http://chris.beams.io/posts/git-commit/#imperative) in the title. For example: `Add Matter lightbulb example`
2. Capitalize the title
3. Do not end the title with a period
4. Separate title from the body with a blank line. If you're committing via GitHub or GitHub Desktop this will be done automatically
5. Wrap body at 72 characters
6. Completely explain the purpose of the commit. Include a rationale for the change, any caveats, side-effects, etc
7. If your commit fixes an issue in the issue tracker, use the [closes/fixes/resolves syntax](https://help.github.com/articles/closing-issues-via-commit-messages) in the body to indicate this
8. Avoid trivial standalone commits like *“fix typo”*, *“ooops”*, *“minor changes”* - squash them into your meaningful commits
9. See [http://chris.beams.io/posts/git-commit](http://chris.beams.io/posts/git-commit) for more tips on writing good commit messages

## Coding style
1. Code formatting should be consistent with the style used in the existing code
2. Use `uncrustify` with the provided configuration file to format your code
    - 2.1 Configuration file is located under `package/uncrustify.cfg`
3. Do not leave any dangling whitespaces
4. Add an empty new line at the end of each file
5. Do not leave commented out code. A record of this code is already preserved in the commit history
6. Define magic numbers as named constants or macros where possible
7. Code - and especially examples must be straight to the point and easily understandable - prioritize understanding over cleverness

## Finding something to contribute
Issues labeled `Up for grabs` are open for community contributions and are a great place to start.

- These issues are not currently assigned to anyone and are available for contributors to pick up
- If you’re interested in working on one, leave a comment on the issue to let others know
- If there has been no activity on an issue for some time, feel free to ask if it’s still available

We encourage you to discuss your approach in the issue before starting work, especially for larger changes. This helps avoid duplicated effort and ensures your contribution aligns with the project’s direction.

You do not need to be assigned before starting work, but communication is encouraged.

## Legal
1. Contributors must sign the CLA via `CLAassistant` - you will be prompted automatically when opening a PR
2. License must be present in all files - and cannot be changed (except for the year)
3. Bringing in third-party dependencies must always be discussed first from a legal perspective
4. Newly created files must be licensed with the Silicon Labs Arduino Core MIT license - and shall have the following license text at the top of each file:
```
/*
 * This file is part of the Silicon Labs Arduino Core
 *
 * The MIT License (MIT)
 *
 * Copyright 2026 Silicon Laboratories Inc. www.silabs.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
```

## General rules
- Be always friendly and civil - treat your fellow users with kindness and patience
- Hostile behavior and harassment of any kind is not tolerated
- Refer to the [Code of Conduct](code_of_conduct.md) for more detailed rules
