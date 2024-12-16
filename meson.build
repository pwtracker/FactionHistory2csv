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
        'decoder': 'DeivdeHistory'
    },
    'FactionBoard2csv': {
        'decoder': 'FactionBoard'
    },
    'StorageHistory2csv': {
        'decoder': 'StorageHistory'
    }
}

add_project_arguments(
    '-DPROJECT_VERSION="@0@"'.format(meson.project_version()),
    '-DPROJECT_CREDITS="Perfect World Tracker (github.com/pwtracker)"',
    language : 'c'
)

foreach target_name, target_options : manifest
    target_src = src
    target_inc = inc

    target_src += files(
        'src' / 'Decoder' / '@0@.c'.format(target_options['decoder'])
    )

    executable(target_name, target_src,
        c_args: [
            '-DPROJECT_NAME="@0@"'.format(target_name)
        ],
        include_directories: target_inc
    )
endforeach
