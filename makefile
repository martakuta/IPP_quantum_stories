FLAGS = -Wall -Wextra -std=c11 -O2

quantization: main.o read_commands.o declare_story.o remove_or_valid_story.o energy.o equal_stories.o trie_structure.o
	gcc $(FLAGS) -o quantization main.o read_commands.o declare_story.o remove_or_valid_story.o energy.o equal_stories.o trie_structure.o

trie_structure.o: trie_structure.c trie_structure.h
	gcc $(FLAGS) -c trie_structure.c

equal_stories.o: equal_stories.c equal_stories.h trie_structure.h
	gcc $(FLAGS) -c equal_stories.c

energy.o: energy.c energy.h equal_stories.h trie_structure.h read_commands.h
	gcc $(FLAGS) -c energy.c

remove_or_valid_story.o: remove_or_valid_story.c remove_or_valid_story.h equal_stories.h
	gcc $(FLAGS) -c remove_or_valid_story.c

declare_story.o: declare_story.c declare_story.h trie_structure.h
	gcc $(FLAGS) -c declare_story.c

read_commands.o: read_commands.c read_commands.h remove_or_valid_story.h equal_stories.h energy.h declare_story.h trie_structure.h
	gcc $(FLAGS) -c read_commands.c

main.o: main.c read_commands.h
	gcc $(FLAGS) -c main.c

clean:
	rm -f *.o quantization
