import os
from pathlib import Path

def main():
    for path in Path('').rglob('*.vert'):
        os.system(f'glslc {path} -o {path}.spv')

    for path in Path('').rglob('*.frag'):
        os.system(f'glslc {path} -o {path}.spv')
        
if __name__ == "__main__":
    main()

    print('Shader compilation succesful!')