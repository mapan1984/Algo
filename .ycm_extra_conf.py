# https://github.com/ycm-core/YouCompleteMe#option-2-provide-the-flags-manually
def Settings(**kwargs):
    # with open('ycm_kwargs', 'w') as f:
    #     f.write(str(kwargs))
    return {
        'flags': [
            '-x', 'c++',
            '-Wall', '-Wextra', '-Werror',
            '-isystem',
            '/usr/include',
            '-isystem',
            '/usr/local/include',

            '-I', 'array',
            '-I', 'utils',
        ],
    }
