project('FactionHistory2csv', 'c',
    version: '1.0.0',
    meson_version: '>=1.5.0',
    license: 'GPLv3',
    license_files: './LICENSE'
)

src = []
inc = []

src += files(
    'src' / 'main.c'
)

inc += include_directories(
    'src'
)

manifest = {
    'DeivdeHistory2csv': {
        'processor': 'DeivdeHistory'
    },
    'FactionBoard2csv': {
        'processor': 'FactionBoard'
    },
    'StorageHistory2csv': {
        'processor': 'StorageHistory'
    },
    'RawHistory2csv': {
        'processor': 'RawHistory'
    }
}

add_project_arguments(
    '-DPROJECT_VERSION="@0@"'.format(meson.project_version()),
    '-DPROJECT_CREDITS="Perfect World Tracker (github.com/pwtracker)"',
    '-D_CRT_SECURE_NO_DEPRECATE',
    '-D_CRT_SECURE_NO_WARNINGS',
    language : 'c'
)

foreach target_name, target_options : manifest
    target_src = src
    target_inc = inc

    target_src += files(
        'src' / 'Processor' / '@0@.c'.format(target_options['processor'])
    )

    executable(target_name, target_src,
        c_args: [
            '-DPROJECT_NAME="@0@"'.format(target_name)
        ],
        include_directories: target_inc
    )
endforeach
